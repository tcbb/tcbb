#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************** 
function:PASA and lumpy share the number of insertions in Hedou12 data 
running Operating System: Windows Server 10   
compiler: Dev-c++-5.11 64-bit
*************************************************************************/ 

typedef struct struc_sv{
	long int start;
	long int end;
	long int length;
}sv;
typedef struct ListElmt_ {

void               *data;
struct ListElmt_   *next;

} ListElmt;
typedef struct List_ {

int                size;

int                (*match)(const void *key1, const void *key2);
void               (*destroy)(void *data);

ListElmt           *head;
ListElmt           *tail;

} List;

void list_init(List *list, void (*destroy)(void *data));

void list_destroy(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)
void list_init(List *list, void (*destroy)(void *data)) {
      list->size = 0;
	  list->destroy = destroy;
	  list->head = NULL;
	  list->tail = NULL;
      return;
}

int list_ins_next(List *list, ListElmt *element, const void *data) {
ListElmt           *new_element;

if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)

   return -1;
new_element->data = (void *)data;

if (element == NULL) {

   if (list_size(list) == 0)

      list->tail = new_element;



   new_element->next = list->head;

   list->head = new_element;

   }else {

   if (element->next == NULL)

      list->tail = new_element;



   new_element->next = element->next;

   element->next = new_element;



}

 list->size++;

 return 0;

}
int list_rem_next(List *list, ListElmt *element, void **data) {

    ListElmt           *old_element;
    if (list_size(list) == 0) return -1;


    if (element == NULL) {
        *data = list->head->data;
         old_element = list->head;
         list->head = list->head->next;
       if (list_size(list) == 1)
        list->tail = NULL;
   }else {
   if (element->next == NULL)

      return -1;
   *data = element->next->data;
   old_element = element->next;
   element->next = element->next->next;
   if (element->next == NULL)

      list->tail = element;
}

free(old_element);

list->size--;
return 0;
}

int main(void)
{
	puts("start");
	puts("....");
	FILE *pasa_data,*lumpy_data,*total_file;
	/* 
	if((simulate_data=fopen("F://data//similation_insertion.txt","r"))==NULL){
		puts("simulate data can not open.");
		exit(0);
	}
	*/ 
	if((pasa_data=fopen("F://data//simulation//pasa//insertion.txt","r"))==NULL){
		puts("PASA data file can not open.");
		exit(0);
	}
	
	if((lumpy_data=fopen("F://data//simulation//lumpy//insertion.txt","r"))==NULL){
		puts("lumpy data file can not open.");
		exit(0);
	}
	
	
	if((total_file=fopen("F://data//simulation//pl_total_insertion.txt","w+"))==NULL){
		puts("pl_total_insertion.txt can not open.");
		exit(0);
	} 
	
	
	
	//extract file
	char line[1024];
	long int a[3];
	long int simulate_count=0;
	long int pasa_count=0;
	long int lumpy_count=0;
	//long int lumpy_count=0;

	while(fgets(line,1024,pasa_data)!=NULL){
		//if()
		  pasa_count++;
		
	}
	//printf("pasa_count=%ld\n",pasa_count);
	rewind(pasa_data);
	sv *pasa_array=(sv*)malloc(pasa_count*sizeof(sv));
	while(fgets(line,1024,lumpy_data)!=NULL){
		//if()
		  lumpy_count++;
		
	}
	//printf("pasa_count=%ld\n",pasa_count);
	rewind(lumpy_data);
	//sv *lumpy_array=(sv*)malloc(lumpy_count*sizeof(sv));

	//printf("pasa_count=%ld\n",pasa_count);
//	rewind(lumpy_data);
	sv *lumpy_array=(sv*)malloc(lumpy_count*sizeof(sv));
	long int s_i=0;
	long int p_i=0;
	long int d_i=0;
	long int l_i=0;
	/* 
    while(fgets(line,1024,simulate_data)!=NULL){ 
            
            char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
            while(p!=NULL){ 
			   a[num]=strtol(p,NULL,10);
               p=strtok(NULL,delim); 
               num++;	
			}//(p!=NULL)
           
           simulate_array[s_i].start=a[0];
           simulate_array[s_i].end=a[1];
           simulate_array[s_i].length=a[2];
           s_i++;
		}//while(!feof(simulate_data)) 
		*/ 
			
	while(fgets(line,1024,pasa_data)!=NULL){ 
            
            char *delim= "\t";
            char *p=strtok(line,delim);
			int num=0; 
            while(p!=NULL){ 
			   a[num]=strtol(p,NULL,10);
               p=strtok(NULL,delim); 
               num++;	
			}//(p!=NULL)
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,a[0],a[1],a[2]);
           pasa_array[p_i].start=a[0];
           pasa_array[p_i].end=a[1];
           pasa_array[p_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,pasa_array[p_i].start,pasa_array[p_i].end,pasa_array[p_i].length);
           p_i++;
         
		}//while(!feof(pasa_data))
	while(fgets(line,1024,lumpy_data)!=NULL){ 
            
            char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
            while(p!=NULL){ 
			   a[num]=strtol(p,NULL,10);
               p=strtok(NULL,delim); 
               num++;	
			}//(p!=NULL)
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,a[0],a[1],a[2]);
           lumpy_array[d_i].start=a[0];
           lumpy_array[d_i].end=a[1];
           lumpy_array[d_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,pasa_array[p_i].start,pasa_array[p_i].end,pasa_array[p_i].length);
           d_i++;
         
		}//while(!feof(pasa_data))  
		
		/* 
		while(fgets(line,1024,lumpy_data)!=NULL){ 
            
            char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
            while(p!=NULL){ 
			   a[num]=strtol(p,NULL,10);
               p=strtok(NULL,delim); 
               num++;	
			}//(p!=NULL)
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,a[0],a[1],a[2]);
           lumpy_array[l_i].start=a[0];
           lumpy_array[l_i].end=a[1];
           lumpy_array[l_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,pasa_array[p_i].start,pasa_array[p_i].end,pasa_array[p_i].length);
           l_i++;
         
		}//while(!feof(pasa_data)) 
		*/
		
		//insertion 
		long int insertion_1=0;
		long int insertion_100=0;
		long int insertion_200=0;
		/* 
		for(long int i=0;i<pasa_count;i++){
		for(long int j=0;j<lumpy_count;j++){
			for(long int z=0;j<lumpy_count;z++){
			
				//printf("%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			if(((pasa_array[i].start>=(lumpy_array[j].start-25))&&(pasa_array[i].start<=(lumpy_array[j].start+25))
			&&(pasa_array[i].start>=(lumpy_array[z].start-25))&&(pasa_array[i].start<=(lumpy_array[z].start+25))
			&&(lumpy_array[j].start>=(lumpy_array[z].start-25))&&(lumpy_array[j].start<=(lumpy_array[z].start+25))
			&&((pasa_array[j].length==lumpy_array[i].length==lumpy_array[z].length)))
			||((pasa_array[i].end>=(lumpy_array[j].end-25))&&(pasa_array[i].end<=(lumpy_array[j].end+25))
			&&(pasa_array[i].end>=(lumpy_array[z].end-25))&&(pasa_array[i].end<=(lumpy_array[z].end+25))
			&&(lumpy_array[z].end>=(lumpy_array[i].end-25))&&(lumpy_array[z].end<=(lumpy_array[i].end+25))
			&&((pasa_array[j].length==lumpy_array[i].length)==lumpy_array[z].length))){
			  	fprintf(analysis_pasa,"%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
				if((pasa_array[j].length>=1)&&(pasa_array[j].length<=99)) insertion_1++;
			  	if((pasa_array[j].length>=100)&&(pasa_array[j].length<=199)) insertion_100++;
			  	if((pasa_array[j].length>=200)&&(pasa_array[j].length<=300)) insertion_200++;
			  }
		}
	}
}
*/ 
//fprintf(total_file,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 

	for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<pasa_count;j++){
				//printf("%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			if(((pasa_array[j].start>=(lumpy_array[i].start-25))&&(pasa_array[j].start<=(lumpy_array[i].start+25))&&((pasa_array[j].length==lumpy_array[i].length)))
			  ||((pasa_array[j].end>=(lumpy_array[i].end-25))&&(pasa_array[j].end<=(lumpy_array[i].end+25))&&((pasa_array[j].length==lumpy_array[i].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
				if((pasa_array[j].length>=1)&&(pasa_array[j].length<=99)) insertion_1++;
			  	if((pasa_array[j].length>=100)&&(pasa_array[j].length<=199)) insertion_100++;
			  	if((pasa_array[j].length>=200)&&(pasa_array[j].length<=300)) insertion_200++;
			  }
		}
	}
	fprintf(total_file,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
	/* 
	fprintf(analysis_pasa,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
	
	    long int d_insertion_1=0;
		long int d_insertion_100=0;
		long int d_insertion_200=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(lumpy_array[i].start-25))&&(lumpy_array[j].start<=(lumpy_array[i].start+25))&&((lumpy_array[j].length==lumpy_array[i].length)))
			  ||((lumpy_array[j].end>=(lumpy_array[i].end-25))&&(lumpy_array[j].end<=(lumpy_array[i].end+25))&&((lumpy_array[j].length==lumpy_array[i].length)))){
			  	fprintf(analysis_lumpy,"%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
				if((lumpy_array[j].length>=1)&&(lumpy_array[j].length<=99)) d_insertion_1++;
			  	if((lumpy_array[j].length>=100)&&(lumpy_array[j].length<=199)) d_insertion_100++;
			  	if((lumpy_array[j].length>=200)&&(lumpy_array[j].length<=300)) d_insertion_200++;
			  }
		}
	}
	fprintf(analysis_lumpy,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",d_insertion_1,d_insertion_100,d_insertion_200);
	
		long int l_insertion_1=0;
		long int l_insertion_100=0;
		long int l_insertion_200=0;
	
	for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(lumpy_array[i].start-25))&&(lumpy_array[j].start<=(lumpy_array[i].start+25))&&((lumpy_array[j].length==lumpy_array[i].length)))
			  ||((lumpy_array[j].end>=(lumpy_array[i].end-25))&&(lumpy_array[j].end<=(lumpy_array[i].end+25))&&((lumpy_array[j].length==lumpy_array[i].length)))){
			  	fprintf(analysis_lumpy,"%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
				if((lumpy_array[j].length>=1)&&(lumpy_array[j].length<=99)) l_insertion_1++;
			  	if((lumpy_array[j].length>=100)&&(lumpy_array[j].length<=199)) l_insertion_100++;
			  	if((lumpy_array[j].length>=200)&&(lumpy_array[j].length<=300)) l_insertion_200++;
			  }
		}
	}
	fprintf(analysis_lumpy,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",l_insertion_1,l_insertion_100,l_insertion_200);
	*/ 
	//fclose(simulate_data);
	fclose(total_file);
	fclose(pasa_data);
	fclose(lumpy_data);
	//fclose(lumpy_data);
//	fclose(analysis_pasa);
	//fclose(analysis_lumpy);
	//fclose(analysis_lumpy);
	puts("finish.");
	return 0;
 } 
