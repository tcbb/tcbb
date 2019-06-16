/*
   The source code of this paper has already been opened on CSDN and Wangyi Blog，their websites are as follow: 
   CSDN website: https://blog.csdn.net/jiazhibo/article/details/83590348
   Wangyi blog website: http://blog.163.com/jia_huiqiang/blog/static/274210021201893171859595/?newFollowBlog
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017610101535655
                        http://blog.163.com/jia_huiqiang/blog/static/274210021201761095045747
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017657833380
   这篇论文的源代码已经公开在CSDN网站和网易博客中，网址如下:
   CSDN 网址: https://blog.csdn.net/jiazhibo/article/details/83590348
   网易博客网址 http://blog.163.com/jia_huiqiang/blog/static/274210021201893171859595/?newFollowBlog
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017610101535655
                        http://blog.163.com/jia_huiqiang/blog/static/274210021201761095045747
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017657833380
   
   paper title： PASA: IDENTIFYING MORE CREDIBLE STRUCTURAL VARIANTS OF HEDOU12
   
   Edit time:2017.5.10
   Reedit time:2018.5.10
   Reedit time:2018.8.2
   
   author:Jia Huiqiang 
   Email: jia_huiqiang@163.com
   
   running Operating System: Windows Server 10   
   compiler：Dev-C++ 4.9.2 64-bit
   运行的操作系统：Windows Server 10, Windouws 服务器 ，版本号是 version10
   运行的编译器是：Dev-C++ 4.9.2 64-bit
   本程序已经在Windows Server10 测试运行完成，对于Linux系统或者MacOS 系统没有进行程序测序和运行。
   如果在在Linux系统或者Mac OS系统下运行，出现bug或者其他问题，请发email：jia_huiqiang@163.com 
   This program has run and has tested on Windouws Serve 1o,and it does not run and does not test on Linux system or Mac OS system.
   If using linux, maybe occur bug or other quesiton, please email:jia_huiqiang@163.com
   
     
双末端read文件的输入格式：比对到参考基因组上的第几号染色体(chr) read的测序ID(sequencing_id)   read的碱基量值(left_read_base_quality)  
                         配对的read的碱基量值(mate_read_base_quality)  read的方向(left_read_orientation) 配对read的方向(mate_right_orientation) 
			             read的末端坐标(left_read_end_coordinate)  配对read的开始坐标(mate_read_end_start_coordinte) 
			             read的序列相似性(left_read_alignned_similarity) 配对read的序列相似性(mate_read_alignned_similarity)
							
							 

分裂read文件的输入格式：比对到参考基因组上的第几号染色体(chr) 分裂read的ID(sequencing_id)  read分裂标志(left_read_split_tag) 配对read分裂标志(mate_read_split_tag)
	                    分裂片段左边的碱基量值(left_split_segment_base_quality) 分裂片段右边的碱基量值(right_split_segment_quality)
	                    分裂片段左边的方向(left_split_segment_oirentation) 分裂片段右边的方向(right_split_segment_orientation)
	                    分裂片段左边的末端坐标(left_split_segment_end_coordinate) 分裂片段的右边的开始坐标(right_split_segment_start_coordinate)
	                   分裂片段左边的序列相似性(left_split_segment_similarity) 分裂片段右边的序列相似性(right_split_segment_similarity)  
	                       
	                       
The paired_end read file formate:chr sequencing_id  left_read_base_quality  mate_read_base_quality 
                                 left_read_orientation mate_right_orientation left_read_end_coordinate
								 mate_read_end_start_coordinte left_read_alignned_similarity
								mate_read_alignned_similarity
									 
The split read file formate:chr sequencing_id left_read_split_tag mate_read_split_tag
	                        left_split_segment_base_quality right_split_segment_quality
	                        left_split_segment_oirentation right_split_segment_orientation
	                        left_split_segment_end_coordinate right_split_segment_start_coordinate
	                        left_split_segment_similarity right_split_segment_similarity 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "structural_variation.h"

#define mean 397.24
#define sd 66.68
#define max_insertion 700
#define min_insertion 100

char *chr[20]={"Chr01","Chr02","Chr03","Chr04","Chr05","Chr06","Chr07","Chr08","Chr09","Chr10",
	           "Chr11","Chr12","Chr13","Chr14","Chr15","Chr16","Chr17","Chr18","Chr19","Chr20"};
static long int every_chr_number[20]={0};
	                 
void list_init(List *list,void(*destroy)(void *data))
{
	list->size=0;
	list->destroy=destroy;
	list->head=NULL;
	list->tail=NULL;
	return;
}
void destroy(void *data)
{
	free(data);
}
void list_destroy(List *list)
{
	void *data;
	while(list_size(list)>0){
		if(list_rem_next(list,NULL,(void**)&data)==0&&list->destroy!=NULL)
		  list->destroy(data);
	}
	memset(list,0,sizeof(list));
}

int list_ins_next(List *list,ListElmt *element,const void *data)
{
	ListElmt *new_element;
	if((new_element=(ListElmt*)malloc(sizeof(ListElmt)))==NULL)
	   return -1;
	new_element->data=(void*)data;
	if(element==NULL){
		if(list_size(list)==0) list->tail=new_element;
		new_element->next=list->head;
		list->head=new_element;
	}
	else{
		if(element->next==NULL) list->tail=new_element;
		new_element->next=element->next;
		element->next=new_element;
	}
	list->size++;
	return 0;
}

int list_rem_next(List *list,ListElmt *element, void **data)
{
	ListElmt *old_element;
	if(list_size(list)==0) return -1;
	if(element==NULL){
		*data=list->head->data;
		old_element=list->head;
		list->head=list->head->next;
		if(list_size(list)==1) list->tail=NULL;
	}else {
		if(element->next==NULL) return -1;
		*data=element->next->data;
		old_element=element->next;
		element->next=element->next->next;
		if(element->next==NULL) list->tail=element;
	} 
	free(old_element);
	list->size--;
	return 0;
}
void display(pe *p)
{
	printf("%s\t%s\n%s\t%s\n%s\t%s\n%ld\t%ld\t%f\n",p->chr,p->sequencing_id,
	                 p->l_base_quality,p->r_base_quality,
					 p->l_o,p->r_o,
					 p->l_end,p->r_start,
					 p->l_seq_similarity,
					 p->r_seq_similarity);
					 
}
void displaylist(List *list,DISPLAY display)
{
	ListElmt *p=list->head;
	while(p!=NULL)
	{
		display(p->data);
		p=p->next;
	}
}
void read_file(FILE *pe_file,FILE *sr_file,List *pe_list,List *sr_list)
{

	pe *node;
	//list_init(pe_list,NULL);
	while(!feof(pe_file)){
		char line[256];
		fgets(line,256,pe_file);
		char *p[10];
		int count=0;  
        for(p[count]= strtok(line, " "); p[count] != NULL; p[count] = strtok(NULL, " ")) {  
            count++;
	    }
		node=(pe*)malloc(sizeof(struct paired_end)); 
		strcpy(node->chr,p[0]);
		strcpy(node->sequencing_id,p[1]);
	    strcpy(node->l_base_quality,p[2]);
	    strcpy(node->r_base_quality,p[3]);
	    strcpy(node->l_o,p[4]);
	    strcpy(node->r_o,p[5]);
	    node->l_end=atol(p[6]);
	    node->r_start=atol(p[7]);
	    node->l_seq_similarity=atof(p[8]); 
	    node->r_seq_similarity=atof(p[9]);
	    list_ins_next(pe_list,list_tail(pe_list),node);
	}
	//fclose(pe_file);
	sr *sr_node;
//	list_init(sr_list,NULL);
	while(!feof(sr_file)){
		char sr_line[256];
		fgets(sr_line,256,sr_file);
		char *sr_p[12];
		int count=0;  
        for(sr_p[count]= strtok(sr_line, " "); sr_p[count] != NULL; sr_p[count] = strtok(NULL, " ")) {  
            count++;
	    }
		sr_node=(sr*)malloc(sizeof(struct split_read)); 
		strcpy(sr_node->chr,sr_p[0]);
		strcpy(sr_node->sequencing_id,sr_p[1]);
		strcpy(sr_node->left_read,sr_p[2]);
		strcpy(sr_node->right_read,sr_p[3]);
	    strcpy(sr_node->l_segment_quality,sr_p[4]);
	    strcpy(sr_node->r_segment_quality,sr_p[5]);
	    strcpy(sr_node->l_o,sr_p[6]);
	    strcpy(sr_node->r_o,sr_p[7]);
	    sr_node->l_segment_end=atol(sr_p[8]);
	    sr_node->r_segment_start=atol(sr_p[9]);
	    sr_node->l_seq_similarity=atof(sr_p[10]);
		sr_node->r_seq_similarity=atof(sr_p[11]); 
	    list_ins_next(sr_list,list_tail(sr_list),sr_node);
	}
	//fclose(sr_file);
}
/*
void read_split_read_file(FILE *sr_file,List *list)
{
	char fname[30];
	puts("Please input the file of the alignned split read:");
	scanf("%s",fname);
	if((sr_file=fopen(fname,"r"))==NULL){
		puts("Don't open this file.'");
		exit(0);
	}
	sr *sr_node;
	
	while(!feof(sr_file)){
		char sr_line[256];
		fgets(sr_line,256,sr_file);
		char *sr_p[10];
		int count=0;  
        for(sr_p[count]= strtok(sr_line, " "); sr_p[count] != NULL; sr_p[count] = strtok(NULL, " ")) {  
            count++;
	    }
		node=(sr*)malloc(sizeof(struct split_read)); 
		strcpy(sr_node->chr,sr_p[0]);
		strcpy(sr_node->sequencing_id,sr_p[1]);
		strcpy(sr_node->left_read,sr_p[2]);
		strcpy(sr_node->right_read,sr_p[3]);
	    strcpy(sr_node->l_segment_quality,sr_p[4]);
	    strcpy(sr_node->r_segment_quality,sr_p[5]);
	    strcpy(sr_node->l_o,sr_p[6]);
	    strcpy(sr_node->r_o,sr_p[7]);
	    sr_node->l_segment_end=atol(sr_p[6]);
	    sr_node->r_segment_start=atol(sr_p[8]);
	    sr_node->seq_similarity=atof(sr_p[9]); 
	    list_ins_next(list,NULL,sr_node);
	}
	fclose(sr_file);
}
*/
void chr_static(pe *p)
{
	for(int i=0;i<20;i++){
		if(strcmp(p->chr,chr[i])==0) every_chr_number[i];
	}
}
long int sum(long int a[],int size)
{
	long int sum=0;
	for(int i=0;i<size;i++)
	   sum+=a[i];
	return sum;
}
int pe_insertion_match(const void *k1,const void *k2)
{
	pe *key1,*key2;
	key1=(pe*)k1;
	key2=(pe*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&
	   (strcmp(key1->l_o,"+")==0)&&
	   (strcmp(key1->r_o,"-")==0)&&
	   (strcmp(key2->l_o,"+")==0)&&
	   (strcmp(key2->r_o,"-")==0)&&
	   (key1->r_start+strlen(key1->r_base_quality)-key1->l_end+strlen(key1->l_base_quality)<mean-3*sd)&&
	   (key2->r_start+strlen(key2->r_base_quality)-key2->l_end+strlen(key2->r_base_quality)<mean-3*sd)&&
	   (abs(key1->l_end-key2->l_end)<104)&&
	   (abs(key1->r_start-key2->r_start)<104)) return 1;
	else
	  return 0;
}
int pe_deletion_match(const void *k1,const void *k2)
{
	pe *key1,*key2;
	key1=(pe*)k1;
	key2=(pe*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&
	   (strcmp(key1->l_o,"+")==0)&&
	   (strcmp(key1->r_o,"-")==0)&&
	   (strcmp(key2->l_o,"+")==0)&&
	   (strcmp(key2->r_o,"-")==0)&&
	   (key1->r_start+strlen(key1->r_base_quality)-key1->l_end+strlen(key1->l_base_quality)>mean+3*sd)&&
	   (key2->r_start+strlen(key2->r_base_quality)-key2->l_end+strlen(key2->r_base_quality)>mean+3*sd)&&
	   (abs(key1->l_end-key2->l_end)<50)&&
	   (abs(key1->r_start-key2->r_start)<50)) return 1;
	else
	  return 0;
 } 

int pe_inversion_match(const void *k1,const void *k2)
{
	pe *key1,*key2;
	key1=(pe*)k1;
	key2=(pe*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&
	   ((strcmp(key1->l_o,"+")==0)&&(strcmp(key1->r_o,"+")==0))&&
	   ((strcmp(key2->l_o,"+")==0)&&(strcmp(key2->r_o,"+")==0))&&
	   (strlen(key1->r_base_quality)+key1->r_start-key1->l_end<3*max_insertion)&&
	   (strlen(key2->r_base_quality)+key2->r_start-key2->l_end<3*max_insertion)&&
	   (abs(key1->l_end-key2->l_end)<104)&&
	   (abs(key1->r_start-key2->r_start)<104)) return 1;
	else if((strcmp(key1->chr,key2->chr)==0)&&
	   ((strcmp(key1->l_o,"-")==0)&&(strcmp(key1->r_o,"-")==0))&&
	   ((strcmp(key2->l_o,"-")==0)&&(strcmp(key2->r_o,"-")==0))&&
	   (key1->r_start-key1->l_end+strlen(key1->l_base_quality)<3*max_insertion)&&
	   (key2->r_start-key2->l_end+strlen(key2->l_base_quality)<3*max_insertion)&&
	   (abs(key1->l_end-key2->l_end)<104)&&
	   (abs(key1->r_start-key2->r_start)<104)) return 2;
	else
	  return 0;
}
int sr_insertion_match(const void *k1,const void *k2)
{
	sr *key1,*key2;
	key1=(sr*)k1;
	key2=(sr*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&
	   ((strcmp(key1->l_o,"+")==0)&&(strcmp(key1->r_o,"+")==0)||
	   (strcmp(key1->l_o,"-")==0&&strcmp(key1->r_o,"-")==0))&&
	   ((strcmp(key2->l_o,"+")==0)&&(strcmp(key2->r_o,"+")==0)||
	   (strcmp(key2->l_o,"-")==0&&strcmp(key2->r_o,"-")==0))&&
	   (key1->l_segment_end>key1->r_segment_start)&&
	   (key2->l_segment_end>key2->r_segment_start)&&
	   (abs(key1->l_segment_end-key2->l_segment_end)<104)&&
	   (abs(key1->r_segment_start-key2->r_segment_start)<104)) return 1;
	else
	  return 0;
}
int sr_deletion_match(const void *k1,const void *k2) 
{
	sr *key1,*key2;
	key1=(sr*)k1;
	key2=(sr*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&
	   ((strcmp(key1->l_o,"+")==0)&&(strcmp(key1->r_o,"+")==0)||
	   (strcmp(key1->l_o,"-")==0&&strcmp(key1->r_o,"-")==0))&&
	   ((strcmp(key2->l_o,"+")==0)&&(strcmp(key2->r_o,"+")==0)||
	   (strcmp(key2->l_o,"-")==0&&strcmp(key2->r_o,"-")==0))&&
	   (key1->r_segment_start-key1->l_segment_end>0)&&
	   (key2->r_segment_start-key2->l_segment_end>0)&&
	   (abs(key1->l_segment_end-key2->l_segment_end)<25)&&
	   (abs(key1->r_segment_start-key2->r_segment_start)<25)) return 1;
	else
	  return 0;
} 
 

int sr_inversion_match(const void *k1,const void *k2)
{
	sr *key1,*key2;
	key1=(sr*)k1;
	key2=(sr*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&
	   (((strcmp(key1->left_read,"l")==0&&strcmp(key1->l_o,"+")==0&&strcmp(key1->r_o,"-"))
	   &&(strcmp(key2->left_read,"l")==0&&strcmp(key2->l_o,"+")==0&&strcmp(key2->r_o,"-")==0))
	   ||((strcmp(key1->right_read,"r")==0&&strcmp(key1->l_o,"-")==0&&strcmp(key1->r_o,"+")==0)&&
	    (strcmp(key2->right_read,"r")==0&&strcmp(key2->l_o,"-")==0&&strcmp(key2->r_o,"+")==0)))&&
       (key1->r_segment_start+strlen(key1->r_segment_quality)-key1->l_segment_end>0)&&
       (key2->r_segment_start+strlen(key2->r_segment_quality)-key2->l_segment_end>0)&&
       (abs(key1->l_segment_end-key2->l_segment_end)<104)&&
       (abs(key1->r_segment_start-key2->r_segment_start)<104)) return 1;
    else if((strcmp(key1->chr,key2->chr)==0)&&
	   (((strcmp(key1->left_read,"l")==0&&strcmp(key1->l_o,"-")==0&&strcmp(key1->r_o,"+"))
	   &&(strcmp(key2->left_read,"l")==0&&strcmp(key2->l_o,"-")==0&&strcmp(key2->r_o,"+")==0))
	   ||((strcmp(key1->right_read,"r")==0&&strcmp(key1->l_o,"+")==0&&strcmp(key1->r_o,"-")==0)&&
	    (strcmp(key2->right_read,"r")==0&&strcmp(key2->l_o,"+")==0&&strcmp(key2->r_o,"-")==0)))&&
       (key1->r_segment_start+strlen(key1->l_segment_quality)-key1->l_segment_end>0)&&
       (key2->r_segment_start+strlen(key2->l_segment_quality)-key2->l_segment_end>0)&&
       (abs(key1->l_segment_end-key2->l_segment_end)<104)&&
       (abs(key1->r_segment_start-key2->r_segment_start)<104)) return 2;
	else
	  return 0;
	
}
long int h(long int i)
{
	return i;
}
long int h_sr(long int i)
{
}
int chtbl_init(CHTbl *htbl,long int buckets,long int (*h)(long int i),int (*match)(const void *key1,const void *key2),void (*destroy)(void *data))
{
	int i;
	if((htbl->table=(List*)malloc(buckets*sizeof(List)))==NULL) return -1;
	htbl->buckets=buckets;
	for(i=0;i<htbl->buckets;i++) list_init(&htbl->table[i],destroy);
	htbl->h=h;
	htbl->match=match;
	htbl->destroy=destroy;
	htbl->size=0;
	return 0;
}
void chtbl_destroy(CHTbl *htbl)
{
	for(int i=0;i<htbl->buckets;i++) list_destroy(&htbl->table[i]);
	free(htbl->table);
	memset(htbl,0,sizeof(CHTbl));
	return ;
}
int chtbl_insert(CHTbl *htbl,const void *data,long int i)
{
	void *temp;
	long int bucket;
	int retval;
	temp=(void*)data;
	if(chtbl_lookup(htbl,&temp,i)==0) return 1;
	bucket=htbl->h(i);
	if(retval=list_ins_next(&htbl->table[bucket],NULL,data)==0) htbl->size++;
	return retval;
}
int chtbl_remove(CHTbl *htbl,void **data,long int i)
{
	ListElmt *element,*prev;
	long int bucket;
	bucket=htbl->h(i);
	prev=NULL;
	for(element=list_head(&htbl->table[bucket]);element!=NULL;list_next(element)){
		if(htbl->match(*data,list_data(element))){
			if(list_rem_next(&htbl->table[bucket],prev,data)==0){
				htbl->size--;
				return 0;
			}else 
			   return -1;
		}
		prev=element;
	}
	return -1;
}
int chtbl_lookup(const CHTbl *htbl,void **data,long int i)
{
	ListElmt *element;
	int bucket;
	bucket=htbl->h(i);
	for(element=list_head(&htbl->table[bucket]);element!=NULL;element=list_next(element)){
		if(htbl->match(*data,list_data(element))){
			*data=list_data(element);
			return 0;
		}
	}
	return -1;
}

void pe_cluster(List *pe_total_set,CHTbl *pe_insertion,CHTbl *pe_deletion,CHTbl *pe_inversion,long int buckets,
                         long int (*h)(long int i),int (*match)(const void *key1,const void *key2),
						 void (*destroy)(void *data))
{
	long int s=sum(every_chr_number,20);
	/*
	chtbl_init(pe_insertion,s,h,pe_insertion_match,NULL);
	chtbl_init(pe_deletion,s,h,pe_deletion_match,NULL);
	chtbl_init(pe_inversion,s,h,pe_inversion_match,NULL);
	*/
	ListElmt *pe_i;
	long int count=0;
	for(pe_i=list_head(pe_total_set);pe_i!=NULL;pe_i=list_next(pe_i),count++)
	{
		long int insertion_number=0,deletion_number=0,inversion_number=0;
		chtbl_insert(pe_insertion,list_data(pe_i),count);
		insertion_number++;
		chtbl_insert(pe_deletion,list_data(pe_i),count);
		deletion_number++;
		chtbl_insert(pe_inversion,list_data(pe_i),count);
		inversion_number++;
		ListElmt *pe_ii=list_next(pe_i);
		while(pe_ii!=NULL){
			if(pe_insertion_match(list_data(pe_i),list_data(pe_ii))==1)
			{
			    chtbl_insert(pe_insertion,list_data(pe_ii),count);
				insertion_number++;	
			}else if(pe_deletion_match(list_data(pe_i),list_data(pe_ii))==1){
				chtbl_insert(pe_deletion,list_data(pe_ii),count);
				deletion_number++;
			}else if(pe_inversion_match(list_data(pe_i),list_data(pe_ii))==1){
				chtbl_insert(pe_inversion,list_data(pe_ii),count);
				inversion_number++;
			}
		    pe_ii=list_next(pe_ii);
		}
		if(insertion_number<2){
			ListElmt *p_r=list_head(&pe_insertion->table[count]);
			//=list_head(&pe_insertion[count]);
			while(p_r!=NULL)
			{
				chtbl_remove(pe_insertion,&list_data(p_r),count);
				p_r=list_next(p_r);
			}	
		}else if(deletion_number<2){
			ListElmt *p_r=list_head(&pe_deletion->table[count]);
			//=list_head(&pe_insertion[count]);
			while(p_r!=NULL)
			{
				chtbl_remove(pe_deletion,&list_data(p_r),count);
				p_r=list_next(p_r);
			}	
		}else if(inversion_number<2){
			ListElmt *p_r=list_head(&pe_inversion->table[count]);
			//=list_head(&pe_insertion[count]);
			while(p_r!=NULL)
			{
				chtbl_remove(pe_inversion,&list_data(p_r),count);
				p_r=list_next(p_r);
			}	
		}		
	}
}
void sr_cluster(List *sr_total_set,CHTbl *sr_insertion,CHTbl *sr_deletion,CHTbl *sr_inversion,long int buckets,
                         long int (*h)(long int i),int (*match)(const void *key1,const void *key2),
						 void (*destroy)(void *data))
{
	long int s=sum(every_chr_number,20);
	/*
	chtbl_init(sr_insertion,s,h,sr_insertion_match,NULL);
	chtbl_init(sr_deletion,s,h,sr_deletion_match,NULL);
	chtbl_init(sr_inversion,s,h,sr_inversion_match,NULL);
	*/
	ListElmt *pe_i;
	long int count=0;
	for(pe_i=list_head(sr_total_set);pe_i!=NULL;pe_i=list_next(pe_i),count++)
	{
		long int insertion_number=0,deletion_number=0,inversion_number=0;
		chtbl_insert(sr_insertion,list_data(pe_i),count);
		insertion_number++;
		chtbl_insert(sr_deletion,list_data(pe_i),count);
		deletion_number++;
		chtbl_insert(sr_inversion,list_data(pe_i),count);
		inversion_number++;
		ListElmt *pe_ii=list_next(pe_i);
		while(pe_ii!=NULL){
			if(sr_insertion_match(list_data(pe_i),list_data(pe_ii))==1)
			{
			    chtbl_insert(sr_insertion,list_data(pe_ii),count);
				insertion_number++;	
			}else if(sr_deletion_match(list_data(pe_i),list_data(pe_ii))==1){
				chtbl_insert(sr_deletion,list_data(pe_ii),count);
				deletion_number++;
			}else if((sr_inversion_match(list_data(pe_i),list_data(pe_ii))==1)||(sr_inversion_match(list_data(pe_i),list_data(pe_ii))==2)){
				chtbl_insert(sr_inversion,list_data(pe_ii),count);
				inversion_number++;
			}
		    pe_ii=list_next(pe_ii);
		}
		if(insertion_number<2){
			ListElmt *p_r=list_head(&sr_insertion->table[count]);
			//=list_head(&pe_insertion[count]);
			while(p_r!=NULL)
			{
				chtbl_remove(sr_insertion,&list_data(p_r),count);
				p_r=list_next(p_r);
			}	
		}else if(deletion_number<2){
			ListElmt *p_r=list_head(&sr_deletion->table[count]);
			while(p_r!=NULL)
			{
				chtbl_remove(sr_deletion,&list_data(p_r),count);
				p_r=list_next(p_r);
			}	
		}else if(inversion_number<2){
			ListElmt *p_r=list_head(&sr_inversion->table[count]);
			while(p_r!=NULL)
			{
				chtbl_remove(sr_inversion,&list_data(p_r),count);
				p_r=list_next(p_r);
			}	
		}		
	}
}
pe pe_coordinate(pe *p)
{
	pe s;
	strcpy(s.chr,p->chr);
	strcpy(s.l_base_quality,p->l_base_quality);
	s.l_end=p->l_end;
	strcpy(s.l_o,p->l_o);
	s.l_seq_similarity=p->l_seq_similarity;
	strcpy(s.r_base_quality,p->r_base_quality);
	strcpy(s.r_o,p->r_o);
	s.r_seq_similarity=p->r_seq_similarity;
	s.r_start=p->r_start;
	strcpy(s.sequencing_id,p->sequencing_id);
	return s;
}
sr sr_coordinate(sr *p)
{
	sr s;
	strcpy(s.chr,p->chr);
	strcpy(s.left_read,p->left_read);
	strcpy(s.right_read,p->right_read);
	strcpy(s.l_o,p->l_o);
	s.l_segment_end=p->l_segment_end;
	strcpy(s.l_segment_quality,p->l_segment_quality);
	s.l_seq_similarity=p->l_seq_similarity;
	strcpy(s.l_segment_quality,p->right_read);
	strcpy(s.r_o,p->r_o);
	strcpy(s.r_segment_quality,p->r_segment_quality);
	s.r_segment_start=p->r_segment_start;
	s.r_seq_similarity=p->r_seq_similarity;
	strcpy(s.sequencing_id,p->sequencing_id);
	return s;
}
sv sv_coordinate(sv *p)
{
	sv s;
	strcpy(s.chr,p->chr);
	s.start=p->start;
	s.end=p->end;
	s.length=p->length;
	return s;
}
sv pe_insertion_out(List *list)
{
	ListElmt *p=list_head(list);
	long int size=list_size(list);
	long int insertion_coordination=0,sum=0;
	pe temp;
	while(p!=NULL){
		temp=pe_coordinate(list_data(p));
		long int m=temp.l_end+temp.r_start;
		insertion_coordination+=m/2;
		long int n=temp.r_start-temp.l_end+strlen(temp.l_base_quality)+strlen(temp.r_base_quality);
		sum+=n;
		p=list_next(p);
	}
	insertion_coordination=insertion_coordination/size;
	sum=sum/size;
	long int length=mean-sum;
	sv out;
	strcpy(out.chr,temp.chr);
	out.start=insertion_coordination;
	out.length=length;
	return out;
	
}
sv pe_deletion_out(List *list)
{
	ListElmt *p;
	p=list_head(list);
	long int size=list_size(list);
	sv out;
	pe s;
	long int left=0,right=0,length;
	while(p!=NULL){
		s=pe_coordinate(list_data(p));
		left+=s.l_end;
		right+=s.r_start;
		p=list_next(p);
	}
	strcpy(out.chr,s.chr);
	left=left/size;
	out.start=left;
	right=right/size;
	out.end=right;
	out.length=abs(left-right);
	return out;
}
sv pe_inversion_out(List *list)
{
   ListElmt *p;
	p=list_head(list);
	long int size=list_size(list);
	sv out;
	pe s;
	long int left=0,right=0,length;
	while(p!=NULL){
		s=pe_coordinate(list_data(p));
		if((strcmp(s.l_o,"+")==0)&&(strcmp(s.r_o,"+")==0)){
		  left+=s.l_end;
		  right+=(s.r_start+strlen(s.r_base_quality));	
		}
		if((strcmp(s.l_o,"-")==0)&&(strcmp(s.r_o,"-")==0)){
			left+=(s.l_end-strlen(s.l_base_quality));
		    right+=s.r_start;
		}
		p=list_next(p);
	}
	strcpy(out.chr,s.chr);
	left=left/size;
	out.start=left;
	right=right/size;
	out.end=right;
	out.length=abs(left-right);
	return out;	
}
sv sr_insertion_out(List *list)
{
	ListElmt *p;
	p=list_head(list);
	long int size=list_size(list);
	sv out;
	sr s;
	long int left=0,length=0;
	while(p!=NULL){
		s=sr_coordinate(list_data(p));
		left+=(s.l_segment_end+s.r_segment_start);
		length=abs(s.l_segment_end-s.r_segment_start);
		p=list_next(p);
	}
	strcpy(out.chr,s.chr);
	left=left/size;
	out.start=left;
	length=length/size;
	out.length=length;
	
}
sv sr_deletion_out(List *list)
{
	ListElmt *p=list_head(list);
	long int size=list_size(list);
	long int left=0,right=0,length=0;
	sv out;
	sr s;
	while(p!=NULL){
		s=sr_coordinate(list_data(p));
		left+=s.l_segment_end;
		right+=s.r_segment_start;
		p=list_next(p);
	}
	strcpy(out.chr,s.chr);
	left=left/size;
	out.start=left;
	right=right/size;
	out.end=right;
	out.length=abs(left-right);
	return out;
}
sv sr_inversion_out(List *list)
{
	sr s;
	sv out;
	long int left=0,right=0,length=0,size;
	size=list_size(list);
	ListElmt *p;
	p=list_head(list);
	while(p!=NULL){
		s=sr_coordinate(list_data(p));
		if(((strcmp(s.left_read,"l")==0)&&(strcmp(s.l_o,"+")==0)&&(strcmp(s.r_o,"-")==0))||
		   ((strcmp(s.right_read,"r")==0)&&(strcmp(s.l_o,"-")==0)&&(strcmp(s.r_o,"+")==0))){
		   	left+=s.l_segment_end;
		   	right+=(s.r_segment_start+strlen(s.r_segment_quality));
		   }
		if(((strcmp(s.left_read,"l")==0)&&(strcmp(s.l_o,"-")==0)&&(strcmp(s.r_o,"+")==0))||
		   ((strcmp(s.right_read,"r")==0)&&(strcmp(s.l_o,"+")==0)&&(strcmp(s.r_o,"-")==0))){
		   	left+=(s.l_segment_end-strlen(s.l_segment_quality));
		   	right+=s.r_segment_start;
		   }
		   p=list_next(p);
	}
	strcpy(out.chr,s.chr);
	left=left/size;
	out.start=left;
	right=right/size;
	out.end=right;
	length=abs(right-left);
	out.length=length;
	return out;	
}
float pe_compute(pe *pp)
{
	float s1=strlen(pp->l_base_quality)*(pp->l_seq_similarity);
	float s2=strlen(pp->r_base_quality)*(pp->r_seq_similarity);
	float s3=strlen(pp->l_base_quality)+strlen(pp->r_base_quality);
	float s=(s1+s2)/s3;
	return s;
}
double pe_quality(pe *pp){
	float s=0.0,s1=0.0,s2=0.0;
	int i,j;
	for(i=0;i<strlen(pp->l_base_quality);i++) 
	  s1+=(int)(pp->l_base_quality[i]);
	//s1=s1*pp->l_seq_similarity;
	for(j=0;j<strlen(pp->r_base_quality);j++)
	  s2+=(int)(pp->r_base_quality[j]);
	//s2=s2*pp->r_seq_similarity;
	s=(float)(s1+s2)/(i+j);
	return s;
}
int pe_cord_match(const void *k1,const void *k2)
{
	pe *key1,*key2;
	key1=(pe*)k1;
	key2=(pe*)k2;
	if((strcmp(key1->chr,key2->chr)==0)&&(strcmp(key1->sequencing_id,key2->sequencing_id)==0)&&
	   (strcmp(key1->l_o,"+")==0)&&(strcmp(key1->r_o,"-")==0)&&(strcmp(key2->l_o,"+")==0)&&(strcmp(key2->r_o,"-")==0)&&
	   (key1->r_start+strlen(key1->r_base_quality)-key1->l_end+strlen(key1->l_base_quality)>100)&&
	   (key2->r_start+strlen(key2->r_base_quality)-key2->l_end+strlen(key2->r_base_quality)<700)) {
	   return 1;
	   }else{
		return 0;
	}
}
int compare_discord(const void *key1,const void *key2)
{
	pe *k1,*k2;
	k1=(pe*)key1;
	k2=(pe*)key2;
	if((0==strcmp(k1->chr,k2->chr))&&(0==(strcmp(k1->sequencing_id,k2->sequencing_id)))){
		return 1;
	}else{
		return 0;
	}
}
double combine(int m,int n)
{
	long long int sum=1;
	if((0==n)||(1==n)) return 1;
	for(int k=1;k<=n;k++)
     sum=(sum*(m-n+k))/k;
	return sum;
}
double pe_weight(List *set,CHTbl *pe_insertion,CHTbl *pe_deletion,CHTbl *pe_inversion,List *pe_total)
{
	long int s=sum(every_chr_number,20);
	double occur_num_sum=1;
	double discord_sum=0;
	int insertion_count,
	    deletion_count,
		inversion_count;
	ListElmt *temp=list_head(set);
	double quality_sum=0.0;
	while(temp!=NULL){
		insertion_count=0,
	    deletion_count=0,
		inversion_count=0;
		long int cord=0;
		long int discord=0;
		int x=0;
		ListElmt *temp1=list_head(set);
		while(NULL!=temp1){
			if(compare_discord(list_data(temp),list_data(temp1))){
				x++;
			}
			temp1=list_next(temp1);
		}
		ListElmt *pet=list_head(pe_total);
		while(NULL!=pet){
			if(pe_cord_match(list_data(temp),list_data(pet))) {
				cord++;
			}
			pet=list_next(pet);
		}
		
		for(long int i=0;i<s;i++){
		  if(chtbl_lookup(pe_insertion,&list_data(temp),i)==0){
		  	insertion_count=1;
		  	discord++;
		  //	break; 
		  }
	}
		for(long int i=0;i<s;i++){
		  if(chtbl_lookup(pe_deletion,&list_data(temp),i)==0){
		  	deletion_count=1;
		  	discord++;
		  //	break; 
		  }
	}
	for(long int i=0;i<s;i++){
		  if(chtbl_lookup(pe_inversion,&list_data(temp),i)==0){
		  	inversion_count=1;
		  	discord++;
		  	//break; 
		  }
	}
	float occur_num;
	if((insertion_count==1&&deletion_count==1&&inversion_count==1))  occur_num=(1.0)/3;
	if((insertion_count==1&&deletion_count==1&&inversion_count==0)||
	   (insertion_count==0&&deletion_count==1&&inversion_count==1)||
	   (insertion_count==0&&deletion_count==1&&inversion_count==1)) occur_num=(1.0)/2;
	if((insertion_count==1&&deletion_count==0&&inversion_count==0)||
	   (insertion_count==0&&deletion_count==1&&inversion_count==0)||
	   (insertion_count==0&&deletion_count==0&&inversion_count==1)) occur_num=1.0;
	   occur_num_sum+=(occur_num*pe_compute(list_data(temp)));
	   quality_sum+=pe_quality(list_data(temp));
	   if(x==1){
	   	discord_sum*=(1+((double)(discord)/cord));
	   }else {
	   	discord_sum*=(1+((double)(discord)/cord))*(combine(discord,x)*(pow(0.5,x)*10*pow(0.5,discord-x)*10));
	   	discord_sum=(double)(discord_sum)/100;
	   }
	   temp=list_next(temp);
	}
	occur_num_sum=(float)(100*occur_num_sum)/(set->size);
	discord_sum*=100;
	quality_sum=(double)quality_sum/(set->size);
	quality_sum/=10;
	quality_sum=1-pow(10,(-quality_sum));
	float p;
	p=(double)(occur_num_sum*quality_sum*discord_sum)/1000;
	return p;
 }
 float sr_compute(sr *pp)
{
	float s=0.0;
	int i,j;
	for(i=0;i<strlen(pp->l_segment_quality);i++) 
	  s+=(int)(pp->l_segment_quality[i]);
	for(j=0;j<strlen(pp->r_segment_quality);j++)
	  s+=(int)(pp->r_segment_quality[j]);
	return s/(i+j);
}
float sr_weight(List *set,CHTbl *sr_insertion,CHTbl *sr_deletion,CHTbl *sr_inversion)
{
	long int s=sum(every_chr_number,20);
	float p=0;
	int insertion_count,
	    deletion_count,
		inversion_count;
	ListElmt *temp=list_head(set);
	int size=list_size(set);
	float occur_num_sum=0.0;
	float quality_sum=0.0;
	float diff_count_sum=0.0;
	while(temp!=NULL){
		insertion_count=0,
	    deletion_count=0,
		inversion_count=0;
		long int diff_count=0;
		for(long int i=0;i<s;i++){
		  if(chtbl_lookup(sr_insertion,&list_data(temp),i)==0){
		  	insertion_count=1;
		    diff_count++;
		  	break; 
		  }
	}
		for(long int i=0;i<s;i++){
		  if(chtbl_lookup(sr_deletion,&list_data(temp),i)==0){
		  	deletion_count=1;
		  	 diff_count++;
		  	break; 
		  }
	}
	for(long int i=0;i<s;i++){
		  if(chtbl_lookup(sr_inversion,&list_data(temp),i)==0){
		  	inversion_count=1;
		  	diff_count++;
		  	break; 
		  }
	}
	float occur_num;
	if((insertion_count==1&&deletion_count==1&&inversion_count==1))  occur_num=(1.0)/3;
	if((insertion_count==1&&deletion_count==1&&inversion_count==0)||
	   (insertion_count==0&&deletion_count==1&&inversion_count==1)||
	   (insertion_count==0&&deletion_count==1&&inversion_count==1)) occur_num=(1.0)/2;
	if((insertion_count==1&&deletion_count==0&&inversion_count==0)||
	   (insertion_count==0&&deletion_count==1&&inversion_count==0)||
	   (insertion_count==0&&deletion_count==0&&inversion_count==1)) occur_num=1.0;
	   occur_num_sum+=occur_num;
	   quality_sum+=sr_compute(list_data(temp));
	   diff_count_sum+=(1-(float)diff_count/(sr_insertion->size+sr_deletion->size+sr_inversion->size));
	  // p+=occur_num*sr_compute(list_data(temp));
	   temp=list_next(temp);
	}
	quality_sum=quality_sum/(set->size);
	quality_sum=quality_sum/10;
	quality_sum=1-pow(10,(-quality_sum));
	occur_num_sum=(float)(100*occur_num_sum)/(set->size);
	diff_count_sum=(float)(100*diff_count_sum)/(set->size);
	float sum=(float)(quality_sum*occur_num_sum*diff_count_sum)/1000;
	/*
	p=p/(10*size);
	
	sum=1-pow(10,(-p));
	*/
	return sum;
 } 
 
void wsc_primal_dual(List *pe_set,CHTbl *pe_insertion,CHTbl *pe_deletion,CHTbl *pe_inversion,
                     List *sr_set,CHTbl *sr_insertion,CHTbl *sr_deletion,CHTbl *sr_inversion,
					 char *result_path)
{
	long int s=sum(every_chr_number,20);
	List *pe_temp_set,*sr_temp_set;
	ListElmt *pe_head,*sr_head;
	List *insertion_out,*deletion_out,*inversion_out;
	if((insertion_out=(List*)malloc(sizeof(List)))==NULL){
		printf("The dynamic allocaton memory fail\n");
		exit(1);
	}
	if((deletion_out=(List*)malloc(sizeof(List)))==NULL){
		printf("The dynamic allocaton memory fail\n");
		exit(1);
	}
	if((inversion_out=(List*)malloc(sizeof(List)))==NULL){
		printf("The dynamic allocaton memory fail\n");
		exit(1);
	}
	list_init(insertion_out,NULL);
	list_init(deletion_out,NULL);
	list_init(inversion_out,NULL);
	pe data;
	//List *pe_insertion_save,*pe_deletion_save,*pe_inversion;
	//if(pe_insertion=(List*)malloc(sizeof(List))==NULL)
	
		double p_max=0,p_insertion=0,
		      p_deletion=0,p_inversion=0;
		long int insertion_c,deletion_c,inversion_c;
		pe_head=list_head(pe_set);
		while(pe_head!=NULL){
			//ListElmt *member=list_data(pe_head);
			//data=pe_coordinate(list_data(pe_head));
			for(long int j=0;j<s;j++) {
				if(chtbl_lookup(pe_insertion,&list_data(pe_head),j)==0)
				{
					p_max=pe_weight(&pe_insertion->table[j],pe_insertion,pe_deletion,pe_inversion,pe_set);
					if(p_insertion<p_max) {
						p_insertion=p_max;
						insertion_c=j;
					}
				}
				if(chtbl_lookup(pe_deletion,&list_data(pe_head),j)==0)
				{
					p_max=pe_weight(&pe_deletion->table[j],pe_insertion,pe_deletion,pe_inversion,pe_set);
					if(p_deletion<p_max) {
						p_deletion=p_max;
						deletion_c=j;
					}
				}
				if(chtbl_lookup(pe_inversion,&list_data(pe_head),j)==0)
				{
					p_max=pe_weight(&pe_inversion->table[j],pe_insertion,pe_deletion,pe_inversion,pe_set);
					if(p_inversion<p_max){
						p_inversion=p_max;
						inversion_c=j;
					} 
				}
			}
			if(p_insertion>p_deletion&&p_insertion>p_inversion){
				sv s;
				s=pe_insertion_out(&pe_insertion->table[insertion_c]);
				list_ins_next(insertion_out,NULL,&s);
				ListElmt *del=list_head(&pe_insertion->table[insertion_c]);
				while(del!=NULL) {
					chtbl_remove(pe_insertion,&list_data(del),insertion_c);
					del=list_next(del);
				}
			}
			if(p_deletion>p_insertion&&p_deletion>p_inversion){
				sv s=pe_deletion_out(&pe_deletion->table[deletion_c]);
				list_ins_next(deletion_out,NULL,&s);
				ListElmt *del=list_head(&pe_deletion->table[deletion_c]);
				while(del!=NULL) {
					chtbl_remove(pe_deletion,&list_data(del),deletion_c);
					del=list_next(del);
				}
			}
			if(p_inversion>p_insertion&&p_inversion>p_deletion){
				sv s=pe_inversion_out(&pe_inversion->table[inversion_c]);
				list_ins_next(inversion_out,NULL,&s);
				ListElmt *del=list_head(&pe_inversion->table[inversion_c]);
				while(del!=NULL) {
					chtbl_remove(pe_inversion,&list_data(del),inversion_c);
					del=list_next(del);
				}
			}
			pe_head=list_next(pe_head);
		}
		//find the split-read set having maximum probability*********************************************************************
		float psr_max=0,psr_insertion=0,
		      psr_deletion=0,psr_inversion=0;
		long int insertionsr_c,deletionsr_c,inversionsr_c;
		sr_head=list_head(sr_set);
		while(sr_head!=NULL){
			//ListElmt *member=list_data(pe_head);
			//data=pe_coordinate(list_data(pe_head));
			for(long int j=0;j<s;j++) {
				if(chtbl_lookup(sr_insertion,&list_data(sr_head),j)==0)
				{
					psr_max=sr_weight(&sr_insertion->table[j],sr_insertion,sr_deletion,sr_inversion);
					if(psr_insertion<psr_max) {
						psr_insertion=psr_max;
						insertionsr_c=j;
					}
				}
				if(chtbl_lookup(sr_deletion,&list_data(sr_head),j)==0)
				{
					psr_max=sr_weight(&sr_deletion->table[j],sr_insertion,sr_deletion,sr_inversion);
					if(psr_deletion<psr_max) {
						psr_deletion=psr_max;
						deletionsr_c=j;
					}
				}
				if(chtbl_lookup(sr_inversion,&list_data(sr_head),j)==0)
				{
					psr_max=sr_weight(&sr_inversion->table[j],sr_insertion,sr_deletion,sr_inversion);
					if(psr_inversion<psr_max){
						psr_inversion=psr_max;
						inversionsr_c=j;
					} 
				}
			}
			if(psr_insertion>psr_deletion&&psr_insertion>psr_inversion){
				sv s;
				s=sr_insertion_out(&sr_insertion->table[insertionsr_c]);
				list_ins_next(insertion_out,NULL,&s);
				ListElmt *del=list_head(&sr_insertion->table[insertionsr_c]);
				while(del!=NULL) {
					chtbl_remove(sr_insertion,&list_data(del),insertionsr_c);
					del=list_next(del);
				}
			}
			if(psr_deletion>psr_insertion&&psr_deletion>psr_inversion){
				sv s=sr_deletion_out(&sr_deletion->table[deletionsr_c]);
				list_ins_next(deletion_out,NULL,&s);
				ListElmt *del=list_head(&sr_deletion->table[deletionsr_c]);
				while(del!=NULL) {
					chtbl_remove(sr_deletion,&list_data(del),deletionsr_c);
					del=list_next(del);
				}
			}
			if(psr_inversion>psr_insertion&&psr_inversion>psr_deletion){
				sv s=sr_inversion_out(&sr_inversion->table[inversionsr_c]);
				list_ins_next(inversion_out,NULL,&s);
				ListElmt *del=list_head(&sr_inversion->table[inversionsr_c]);
				while(del!=NULL) {
					chtbl_remove(sr_inversion,&list_data(del),inversionsr_c);
					del=list_next(del);
				}
			}
			sr_head=list_next(sr_head);
		}
	char *insertion_path=(char *)malloc(sizeof(char)*(strlen("insertion.txt")+strlen(result_path)+1));
	strcpy(insertion_path,result_path);
	strcat(insertion_path,"insertion.txt");
	FILE *insertion_file;
	if((insertion_file=fopen(insertion_path,"w"))==NULL){
		puts("Dont't open file.\n");
		exit(1);
	}
	ListElmt *head_insertion=list_head(insertion_out);		
	for(int i=0;i<20;i++){
	   while(head_insertion!=NULL){
		   sv insertion_data=sv_coordinate(list_data(head_insertion));
			if(strcmp(chr[i],insertion_data.chr)==0){
		   	       fprintf(insertion_file,"%s\t%ld\t%ld\n",insertion_data.chr,insertion_data.start,insertion_data.length);
			}
		          head_insertion=list_next(head_insertion);
		   }
		   head_insertion=list_head(insertion_out);	
		}
	fclose(insertion_file);
	char *deletion_path=(char *)malloc(sizeof(char)*(strlen("deletion.txt")+strlen(result_path)+1));
	strcpy(deletion_path,result_path);
	strcat(deletion_path,"deletion.txt");
	FILE *deletion_file;
	if((deletion_file=fopen(deletion_path,"w"))==NULL){
		puts("Dont't open file.\n");
		exit(1);
	}
	ListElmt *head_deletion=list_head(deletion_out);		
	for(int i=0;i<20;i++){
	   while(head_deletion!=NULL){
		   sv deletion_data=sv_coordinate(list_data(head_deletion));
			if(strcmp(chr[i],deletion_data.chr)==0){
		   	       fprintf(deletion_file,"%s\t\t%ld\t\t%ld\t\t%ld\n",deletion_data.chr,deletion_data.start,
					                                           deletion_data.end,deletion_data.length);
			}
		          head_deletion=list_next(head_deletion);
		   }
		   head_deletion=list_head(deletion_out);	
		}
	fclose(deletion_file);
	char *inversion_path=(char *)malloc(sizeof(char)*(strlen("inversion.txt")+strlen(result_path)+1));
	strcpy(inversion_path,result_path);
	strcat(inversion_path,"inversion.txt");
	FILE *inversion_file;
	if((inversion_file=fopen(inversion_path,"w"))==NULL){
		puts("Dont't open file.\n");
		exit(1);
	}
	ListElmt *head_inversion=list_head(inversion_out);		
	for(int i=0;i<20;i++){
	   while(head_inversion!=NULL){
		   sv inversion_data=sv_coordinate(list_data(head_inversion));
			if(strcmp(chr[i],inversion_data.chr)==0){
		   	       fprintf(inversion_file,"%s\t\t%ld\t\t%ld\t\t%ld\n",inversion_data.chr,inversion_data.start,
					                                           inversion_data.end,inversion_data.length);
			}
		          head_inversion=list_next(head_inversion);
		   }
		   head_inversion=list_head(inversion_out);	
		}
	fclose(inversion_file);
	free(insertion_out);
	free(deletion_out);
	free(inversion_out);
}

int main(void)
{
	List *pe_total_set=(List*)malloc(sizeof(List));
	List *sr_total_set=(List*)malloc(sizeof(List));
	list_init(pe_total_set,free);
	list_init(sr_total_set,free); 
	FILE *pe_file,*sr_file,*result_file;
	
	fprintf(stdout,"programing start.\n..............\n");
	char pe_fname[30];
	puts("Please input the file of the alignned paired-end:");
	scanf("%s",pe_fname);
	if((pe_file=fopen(pe_fname,"r"))==NULL){
		printf("Don't open:%s\n",pe_fname);
		exit(0);
	}
	
	
	char sr_fname[30];
	puts("Please input the file of the alignned splt-read:");
	scanf("%s",sr_fname);
	if((sr_file=fopen(sr_fname,"r"))==NULL){
		printf("Don't open:%s\n",sr_fname);
		exit(0);
	}
	
	puts("Please input the file path of the result:");
	char result_path[30];
	scanf("%s",result_path);
	//FILE *result_file=fopen(result_pat,"w");
	/*
	if((result_file=fopen(result_path,"w+"))==NULL){
		printf("Don't open:%s\n",result_path);
		exit(0);
	}
	*/
	
	char s[255]; 
	char chr[6], leftReadID[50],leftReadQ[105],rightReadQ[105],leftReadO[2],rightReadO[2];
	long int leftReadS,rightReadE;
	float leftReadSi,rightReadSi;
	if(NULL==fgets(s,255,pe_file)){
			fprintf(stdout,"The file of the aligned paired-end can't be empty.\n");
			exit(1);
		}//remove the header of the aligned paired-end file
	int nullPE_i=0;
	while(NULL!=fgets(s,255,pe_file)){
		/*
		if(NULL==fgets(s,255,pe_file)){
			fprintf(stdout,"The file of the aligned paired-end:%s can't be empty.\n",s);
			exit(1);
		}*/
		if((0==nullPE_i)&&(strlen(s)==0)){
			fprintf(stdout,"The file of the alignned paired-end:%s don't have data.\n");
			exit(1);
		}
		else{
			char *p=strtok(s," ");
			if(NULL!=p){
				strncpy(chr,p,3);
				chr[4]='\0';
				if((0!=strcmp(chr,"CHR"))||(0!=strcmp(chr,"CHr"))||(0!=strcmp(chr,"Chr"))||(0!=strcmp(chr,"chr"))) {
					fprintf(stdout,"chr format error:%s. Valid format: CHAR**or CHr**orChr** or chr**,for example CHR01.\n",chr);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				strncpy(leftReadID,p,1);
				leftReadID[2]='\0';
				if(0!=strcmp(leftReadID,"@")) {
					fprintf(stdout,"sequencing_id format error:%s.Valid format: begin @_\'s data.\n",leftReadID);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else 
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				strcpy(leftReadQ,p);
				if(0<=strlen(leftReadQ)<=104) 
				  p=strtok(NULL," ");
				else{
					fprintf(stdout,"left_read_base_quality  format error:%s. Valid format: the string consisting characters between 0~255.\n",leftReadQ);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				strcpy(rightReadQ,p);
				if(0<=strlen(rightReadQ)<=104) 
				  p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_read_base_quality format error:%s. Valid format: the string consisting characters between 0~255.\n",rightReadQ);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				strcpy(leftReadO,p);
				if((0!=strcmp(leftReadO,"+"))||(0!=strcmp(leftReadO,"-"))) {
					fprintf(stdout,"left_read_orientation fomrat error:%s. Valid format: '-' or '+'.\n",leftReadO);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				strcpy(rightReadO,p);
				if((0!=strcmp(rightReadO,"+"))||(0!=strcmp(rightReadO,"-"))){
					fprintf(stdout,"right_right_orientation format error:%s. Valid format:'-' or '+'.\n",rightReadO);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				sscanf(p,"%ld",&leftReadS);
				if(leftReadS>0)
				   p=strtok(NULL," ");
				else {
					fprintf(stdout,"left_read_end_coordinate format error:%ld. Valid format: integer digital.\n",leftReadS);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				sscanf(p,"%ld",&rightReadE);
				if(rightReadE>0)
				   p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_read_end_start_coordinte format error:%ld. Valid format: integer digital.\n",rightReadE);
					fprintf(stdout,"program exit.\n");
					exit(1);
				} 
			}
			if(NULL!=p){
				sscanf(p,"%f",&leftReadSi);
				if(leftReadSi>1e-10)
				   p=strtok(NULL," ");
				else {
					fprintf(stdout,"left_read_alignned_similarity format error:%f. Valid format: fractional digit.\n",leftReadSi);
					fprintf(stdout,"program exit.\n");
					exit(1);
				} 
				
			}
			if(NULL!=p){
				sscanf(p,"%f",&rightReadSi);
				if(rightReadSi>1e-10)
				   p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_read_alignned_similarity format error: %f\n. Valid format: fractional digit.",rightReadSi);
					fprintf(stdout,"program exit.\n");
					exit(1);
				} 
				  
			}
			//p=strtok()
		}
	}
	rewind(pe_file);
	
	
	
	if(NULL==fgets(s,255,sr_file)){
			fprintf(stdout,"The file of the alignned splt-read can't be empty.\n");
			exit(1);
		}//remove the header of the alignned split-read file
	int nullSR_i=0;
	while(NULL!=fgets(s,255,sr_file)){
		
		if((0==nullSR_i)&&(strlen(s)==0)){
			fprintf(stdout,"The file of the alignned splt-read don't have data.\n");
			fprintf(stdout,"program exit.\n");
			exit(1);
		}else{
			char *p=strtok(s," ");
			if(NULL!=p){
				strncpy(chr,p,3);
				chr[4]='\0';
				if((0!=strcmp(chr,"CHR"))||(0!=strcmp(chr,"CHr"))||(0!=strcmp(chr,"Chr"))||(0!=strcmp(chr,"chr"))) {
					fprintf(stdout,"chr format error:%s. Valid format:CHAR**or CHr**orChr** or chr**,for example CHR01.\n",chr);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				strncpy(leftReadID,p,1);
				leftReadID[2]='\0';
				if(0!=strcmp(leftReadID,"@")) {
					fprintf(stdout,"sequencing_id  format error:%s. Valid format: begin @_ data.\n",leftReadID);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else 
				   p=strtok(NULL," ");
			}
			int leftSplitT;
			if(NULL!=p){
				sscanf(p,"%d",&leftSplitT);
				if(0==leftSplitT||1==leftSplitT) p=strtok(NULL," ");
				else{
					fprintf(stdout,"left_read_split_tag format error:%s. Valid format: 1 or 1.\n",leftSplitT);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			int rightSplitT;
			if(NULL!=p){
				sscanf(p,"%d",&rightSplitT);
				if(0==rightSplitT||1==rightSplitT) p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_read_split_tag format error:%s. Valid format: 1 or 0.\n",rightSplitT);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				strcpy(leftReadQ,p);
				if(0<=strlen(leftReadQ)<=104) 
				  p=strtok(NULL," ");
				else{
					fprintf(stdout,"left_split_segment_base_quality format error:%s. Valid format: the string consisting characters between 0~255.\n",leftReadQ);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				strcpy(rightReadQ,p);
				if(0<=strlen(rightReadQ)<=104) 
				  p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_split_segment_quality format error:%s. Valid format: the string consisting characters between 0~255.\n",rightReadQ);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				strcpy(leftReadO,p);
				if((0!=strcmp(leftReadO,"+"))||(0!=strcmp(leftReadO,"-"))) {
					fprintf(stdout,"left_split_segment_oirentation fomrat error:%s. Valid format: + or -.\n",leftReadO);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				strcpy(rightReadO,p);
				if((0!=strcmp(rightReadO,"+"))||(0!=strcmp(rightReadO,"-"))){
					fprintf(stdout,"right_split_segment_orientation format error:%s. Valid format: + or -.\n",rightReadO);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}else
				   p=strtok(NULL," ");
			}
			if(NULL!=p){
				sscanf(p,"%ld",&leftReadS);
				if(leftReadS>0)
				   p=strtok(NULL," ");
				else {
					fprintf(stdout,"left_split_segment_end_coordinate format error:%ld. Valid format: the integer digital.\n",leftReadS);
					fprintf(stdout,"program exit.\n");
					exit(1);
				}
			}
			if(NULL!=p){
				sscanf(p,"%ld",&rightReadE);
				if(rightReadE>0)
				   p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_split_segment_start_coordinate format error:%ld. Valid format: the integer digital.\n",rightReadE);
					fprintf(stdout,"program exit.\n");
					exit(1);
				} 
			}
			if(NULL!=p){
				sscanf(p,"%f",&leftReadSi);
				if(leftReadSi>1e-10)
				   p=strtok(NULL," ");
				else {
					fprintf(stdout,"left_split_segment_similarity format error:%f. Valid format: fractional digit.\n",leftReadSi);
					fprintf(stdout,"program exit.\n");
					exit(1);
				} 
				
			}
			if(NULL!=p){
				sscanf(p,"%f",&rightReadSi);
				if(rightReadSi>1e-10)
				   p=strtok(NULL," ");
				else{
					fprintf(stdout,"right_split_segment_similarity  format error: %f. Valid format: fractional digital.\n",rightReadSi);
				    fprintf(stdout,"program exit.\n");
					exit(1);
				} 
				  
			}
			//p=strtok()
		}
	}
	
	rewind(sr_file);
	
	
	
	//char *result_file=(char*)malloc(sizeof(FILE));
	read_file(pe_file,sr_file,pe_total_set,sr_total_set);
	//read_paired_end_file(pe_file,pe_total_set);
	//read_split_read_file(sr_file,sr_total_set);
	
	ListElmt *pe_p=list_head(pe_total_set);
	while(pe_p!=NULL){
		chr_static(pe_p->data);
		pe_p=list_next(pe_p);
	}
	ListElmt *sr_p=list_head(sr_total_set);
	while(sr_p!=NULL){
		chr_static(sr_p->data);
		sr_p=list_next(sr_p);
	}
	CHTbl *pe_insertion,*pe_deletion,*pe_inversion;
	if((pe_insertion=(CHTbl*)malloc(sizeof(CHTbl)))==NULL){
		puts("pe_insertion Dynamic allocated memory fail.");
		exit(1);
	}
	if((pe_deletion=(CHTbl*)malloc(sizeof(CHTbl)))==NULL){
		puts("pe_deletion Dynamic allocated memory fail.");
		exit(1);
	}
	if((pe_inversion=(CHTbl*)malloc(sizeof(CHTbl)))==NULL){
		puts("pe_inversion Dynamic allocated memory fail.");
		exit(1);
	}
	long int pe_ss=sum(every_chr_number,20);
	chtbl_init(pe_insertion,pe_ss,h,pe_insertion_match,NULL);
	chtbl_init(pe_deletion,pe_ss,h,pe_deletion_match,NULL);
	chtbl_init(pe_inversion,pe_ss,h,pe_inversion_match,NULL);
	long int pe_s;
	//chtbl_init(CHTbl *htbl,long int buckets,long int (*h)(long int i),int (*match)(const void *key1,const void *key2),void (*destroy)(void *data))
	pe_cluster(pe_total_set,pe_insertion,pe_deletion,pe_inversion,pe_s,h,pe_insertion_match,NULL);
	CHTbl *sr_insertion,*sr_deletion,*sr_inversion;
	if((sr_insertion=(CHTbl*)malloc(sizeof(CHTbl)))==NULL){
		puts("sr_insertion Dynamic allocated memory fail.");
		exit(1);
	}
	if((sr_deletion=(CHTbl*)malloc(sizeof(CHTbl)))==NULL){
		puts("sr_deletion Dynamic allocated memory fail.");
		exit(1);
	}
	if((sr_inversion=(CHTbl*)malloc(sizeof(CHTbl)))==NULL){
		puts("sr_inversion Dynamic allocated memory fail.");
		exit(1);
	}
	long int sr_s;
	long int sr_ss=sum(every_chr_number,20);
	chtbl_init(sr_insertion,sr_ss,h,sr_insertion_match,NULL);
	chtbl_init(sr_deletion,sr_ss,h,sr_deletion_match,NULL);
	chtbl_init(sr_inversion,sr_ss,h,sr_inversion_match,NULL);
	sr_cluster(sr_total_set,sr_insertion,sr_deletion,sr_inversion,sr_s,h,pe_insertion_match,NULL);
	wsc_primal_dual(pe_total_set,pe_insertion,pe_deletion,pe_inversion,
                         sr_total_set,sr_insertion,sr_deletion,sr_inversion,
						 result_path);
	//displaylist(pe_total_set,(DISPLAY)display);
	//displaylist(sr_total_set,(DISPLAY)display);
	chtbl_destroy(pe_insertion);
	chtbl_destroy(pe_deletion);
	chtbl_destroy(pe_inversion);
	chtbl_destroy(sr_insertion);
	chtbl_destroy(sr_deletion);
	chtbl_destroy(sr_inversion);
	list_destroy(pe_total_set);
	list_destroy(sr_total_set);
	free(pe_file);
	free(sr_file);
	fclose(pe_file);
	fclose(sr_file);
//	fclose(result_file);
	printf("This program finishes.\n");
	return 0;
}
