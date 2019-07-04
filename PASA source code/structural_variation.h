/*
   The source code of this paper has already been opened on CSDN and Wangyi Blog��their websites are as follow: 
   CSDN website: https://blog.csdn.net/jiazhibo/article/details/83590348
   Wangyi blog website: http://blog.163.com/jia_huiqiang/blog/static/274210021201893171859595/?newFollowBlog
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017610101535655
                        http://blog.163.com/jia_huiqiang/blog/static/274210021201761095045747
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017657833380
   ��ƪ���ĵ�Դ�����Ѿ�������CSDN��վ�����ײ����У���ַ����:
   CSDN ��ַ: https://blog.csdn.net/jiazhibo/article/details/83590348
   ���ײ�����ַ http://blog.163.com/jia_huiqiang/blog/static/274210021201893171859595/?newFollowBlog
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017610101535655
                        http://blog.163.com/jia_huiqiang/blog/static/274210021201761095045747
                        http://blog.163.com/jia_huiqiang/blog/static/2742100212017657833380
   
   paper title�� PASA: IDENTIFYING MORE CREDIBLE STRUCTURAL VARIANTS OF HEDOU12
   
   Edit time:2017.5.10
   Reedit time:2018.5.10
   Reedit time:2018.8.2
   
   author:Jia Huiqiang 
   Email: jia_huiqiang@163.com
   
   running Operating System: Windows Server 10   
   compiler��Dev-C++ 4.9.2 64-bit
   ���еĲ���ϵͳ��Windows Server 10, Windouws ������ ���汾���� version10
   ���еı������ǣ�Dev-C++ 4.9.2 64-bit
   �������Ѿ���Windows Server10 ����������ɣ�����Linuxϵͳ����MacOS ϵͳû�н��г����������С�
   �������Linuxϵͳ����Mac OSϵͳ�����У�����bug�����������⣬�뷢email��jia_huiqiang@163.com 
   This program has run and has tested on Windouws Serve 1o,and it does not run and does not test on Linux system or Mac OS system.
   If using linux, maybe occur bug or other quesiton, please email:jia_huiqiang@163.com
   
      
   
˫ĩ��read�ļ��������ʽ���ȶԵ��ο��������ϵĵڼ���Ⱦɫ��(chr) read�Ĳ���ID(sequencing_id)   read�ļ����ֵ(left_read_base_quality)  
                          ��Ե�read�ļ����ֵ(mate_read_base_quality)  read�ķ���(left_read_orientation) ���read�ķ���(mate_right_orientation) 
			              read��ĩ������(left_read_end_coordinate)  ���read�Ŀ�ʼ����(mate_read_end_start_coordinte) 
			             read������������(left_read_alignned_similarity) ���read������������(mate_read_alignned_similarity)
							
							 

����read�ļ��������ʽ���ȶԵ��ο��������ϵĵڼ���Ⱦɫ��(chr) ����read��ID(sequencing_id)  read���ѱ�־(left_read_split_tag) ���read���ѱ�־(mate_read_split_tag)
	                   ����Ƭ����ߵļ����ֵ(left_split_segment_base_quality) ����Ƭ���ұߵļ����ֵ(right_split_segment_quality)
	                   ����Ƭ����ߵķ���(left_split_segment_oirentation) ����Ƭ���ұߵķ���(right_split_segment_orientation)
	                   ����Ƭ����ߵ�ĩ������(left_split_segment_end_coordinate) ����Ƭ�ε��ұߵĿ�ʼ����(right_split_segment_start_coordinate)
	                  ����Ƭ����ߵ�����������(left_split_segment_similarity) ����Ƭ���ұߵ�����������(right_split_segment_similarity)  
	                       
	                       
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

#ifndef structural_variation_H 
#define structual_variation_H
#include <stdio.h>
typedef void(*DISPLAY)(void*);
typedef struct paired_end{
	char l_o[2];
	char r_o[2];
	char chr[6];
	char sequencing_id[35];
	char l_base_quality[105];
	char r_base_quality[105];
	long int l_end;
	long int r_start;
	float l_seq_similarity;
	float r_seq_similarity;
}pe;
typedef struct split_read{
	char l_o[2];
	char r_o[2];
	char left_read[2];
	char right_read[2];
    char chr[6];
	char sequencing_id[35];
	char l_segment_quality[74];
	char r_segment_quality[74];
	long int l_segment_end;
	long int r_segment_start;
	float l_seq_similarity;
	float r_seq_similarity;
}sr;
typedef struct list_element_{
	void *data;
	struct list_element_ *next;
}ListElmt;
typedef struct list_{
	long int size;
	int (*match)(const void *key1,const void *key2);
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
}List;
typedef struct CHTbl_{
	int buckets;
	long int (*h)(long int i);
	int (*match)(const void *key1,const void *key2);
	void (*destroy)(void *data);
	long int size;
	List *table; 
}CHTbl;
typedef struct sv_{
	char chr[6];
	long int start;
	long int end;
	long int length;
}sv;
//single linked list bublic interface
void list_init(List *list,void(*destroy)(void *data));
void lsit_destroy(List *list);
int list_ins_next(List *list,ListElmt *element,const void *data);
int list_rem_next(List *list,ListElmt *element,void** data);
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list)((list)->tail)
#define list_is_head(list,element) ((element)==(list)->head?1:0)
#define list_is_tail(element) ((element)->next==NULL?1:0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
//table public interface
int chtbl_init(CHTbl *htbl,long int buckets,long int (*h)(long int i),int (*match)(const void *key1,const void *key2),void (*destroy)(void *data));
void chtbl_destroy(CHTbl *htbl);
int chtbl_insert(CHTbl *htbl,const void *data,long int i);
int chtbl_remove(CHTbl *htbl,void **data,long int i);
int chtbl_lookup(const CHTbl *htbl,void **data,long int i);
#define chtbl_size(htbl) ((htbl)->size);

//data public interface 
void read_file(FILE *pe_file,FILE *sr_file,List *pe_list,List *sr_list);
int pe_insertion_match(const void *key1,const void *key2);
int sr_insertion_match(const void *key1,const void *key2);
int pe_delete_match(const void *key1,const void *key2);
int sr_delete_match(const void *key1,const void *key2);
int pe_inversion_match(const void *key1,const void *key2);
int sr_inversion_match(const void *key1,const void *key2); 
pe pe_coordinate(pe *p);
sr sr_coordinate(sr *p);
sv sv_coordinate(sv *p);
sv pe_insertion_out(List *list);
sv pe_deletion_out(List *list);
sv pe_inversion_out(List *list);
sv sr_insertion_out(List *list);
sv sr_deletion_out(List *list);
sv sr_inversion_out(List *list);
float pe_compute(pe *pp);
int pe_cord_match(const void *k1,const void *k2);
int compare_discord(const void *key1,const void *key2);
double pe_quality(pe *pp);
double combine(int m,int n);
double pe_weight(List *set,CHTbl *pe_insertion,CHTbl *pe_deletion,CHTbl *pe_inversion,List *pe_total);
float sr_compute(sr *pp);
float sr_weight(List *set,CHTbl *sr_insertion,CHTbl *sr_deletion,CHTbl *sr_inversion);
long int h(long int);
long int h_sr(long int );
void chr_static(pe *p);
long int sum(long int a[],int size); 
void pe_cluster(List *pe_total_set,CHTbl *pe_insertion,CHTbl *pe_deletion,CHTbl *pe_inversion,long int buckets,
                         long int (*h)(long int i),int (*match)(const void *key1,const void *key2),
						 void (*destroy)(void *data));
void sr_cluster(List *sr_total_set,CHTbl *sr_insertion,CHTbl *sr_deletion,CHTbl *sr_inversion,long int buckets,
                         long int (*h)(long int i),int (*match)(const void *key1,const void *key2),
						 void (*destroy)(void *data));
void wsc_primal_dual(List *pe_set,CHTbl *pe_insertion,CHTbl *pe_deletion,CHTbl *pe_inversion,
                     List *sr_set,CHTbl *sr_insertion,CHTbl *sr_deletion,CHTbl *sr_inversion,
					 char *result_path);
#endif
