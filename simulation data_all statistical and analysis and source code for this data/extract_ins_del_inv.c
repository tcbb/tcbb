#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/****************************************************************************** 
function:extract insertion,deletion,inversion from BEDPE format file. In here, this programing extract insertion,deletion,inversion from LUMPY.
If need,only change file path and file name. In this program,we only extract LUMPY coordinates between [start-25,start+25] and and [end-25,end+25](including start-25,
start+25,end-25,end+25) comparing simulate data, other discard.
output result: start_coordinate  end_coordinate  sv_length

running Operating System: Windows Server 10   
compiler£ºTDM-GCC 4.9.2 64-bit

*************************************************************************/ 
typedef struct structural_variation{
	long int start;
	long int end;
	long int length;
}sv;
 
int main(void)
{
	FILE *read_insertion,*read_deletion,*read_inversion,*simulate_insertion,*simulate_deletion,*simulate_inversion;
	FILE *write_insertion,*write_deletion,*write_inversion;
	if((simulate_insertion=fopen("F://data//simulate_insertion.csv","r"))==NULL)//change input file path
	{
		printf("%s","simulate_insertion.csv can not be opened."); 
		exit(1);
	}
	if((simulate_deletion=fopen("F://data//simulate_deletion.csv","r"))==NULL)//change input file path
	{
		printf("%s","simulate_deletion.csv can not be opened."); 
		exit(1);
	}
	if((simulate_insertion=fopen("F://data//imulate_inversion.csv","r"))==NULL)//change input file path
	{
		printf("%s","simulate_inversion.csv can not be opened."); 
		exit(1);
	}
	if((read_insertion=fopen("F://data//insertion.csv","r"))==NULL)//change input file path
	{
		printf("%s","The file can not be opened."); 
		exit(1);
	}
    
    if((read_deletion=fopen("F://data//deletion.csv","r"))==NULL)//chage input file path
    {
        printf("%s","The file can not be opened."); 
		exit(1);
    }
    if((read_inversion=fopen("F://data//inversion.csv","r"))==NULL)//change input file path
    {
        printf("%s","The file can not be opened."); 
		exit(1);
    }
    if((write_insertion=fopen("F://data//LUMPY_insertion.txt","w+"))==NULL)//change output file path
    {
        printf("%s","The file can not be opened."); 
		exit(1);
    }
    if((write_deletion=fopen("F://data//UMPY_deletion.txt","w+"))==NULL)//change output file path
    {
        printf("%s","The file can not be opened."); 
		exit(1);
    }
    if((write_inversion=fopen("F://data//LUMPY_inversion.txt","w+"))==NULL)//change output file path
	    {
        printf("%s","The file can not be opened."); 
		exit(1);
    }
   //insertion operation
   char line[1024];
   long int s_i_count=0;
   while(!feof(simulate_insertion)){
   	if((fgets(line,1024,simulate_insertion))!=NULL) s_i_count++;
   }
   sv *simulate_insertion_array=(sv*)malloc(sizeof(sv)*s_i_count);
   rewind(simulate_insertion);
   s_i_count=0;
   while(!feof(simulate_insertion)){
   	if((fgets(line,1024,simulate_insertion))!=NULL){
   		char *delim="\t";
   		char *p=strtok(line,delim);
   		int c=0;
   		long int a[3];
   		while(p!=NULL){ 
			a[c]=strtol(p,NULL,10);
			c++;
            p=strtok(NULL,delim); 
           }
           simulate_insertion_array[s_i_count].start=a[0];
           simulate_insertion_array[s_i_count].end=a[1];
           simulate_insertion_array[s_i_count].length=a[2];
           s_i_count++;
		}
   }
   long int r_i_count=0;
   while(!feof(read_insertion)){
   	if((fgets(line,1024,read_insertion))!=NULL) r_i_count++;
   }
   sv *read_insertion_array=(sv*)malloc(sizeof(sv)*r_i_count);
   rewind(read_insertion);
   r_i_count=0;
   fgets(line,1024,read_insertion);
   while(!feof(read_insertion)){ 
	        fgets(line,1024,read_insertion);
			char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
			int num_i=0;
			long int r_a[5];
            while(p!=NULL){ 
			  if(num==2||num==3||num==5||num==6||num==7) {
			     r_a[num_i]=strtol(p,NULL,10);
			     num_i++;
			  }
			num++;
            p=strtok(NULL,delim); 
           }
           read_insertion_array[r_i_count].start=r_a[0];
           read_insertion_array[r_i_count].end=r_a[2];
           read_insertion_array[r_i_count].length=r_a[4];
           r_i_count++;
		   //fprintf(write_insertion,"%s","\n");  
		   } 
	for(long int i=0;i<s_i_count;i++){
		for(long int j=0;j<r_i_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((read_insertion_array[j].start>=(simulate_insertion_array[i].start-25))&&(read_insertion_array[j].start<=(simulate_insertion_array[i].start+25)))
			  ||((read_insertion_array[j].end>=(simulate_insertion_array[i].end-25))&&(read_insertion_array[j].end<=(simulate_insertion_array[i].end+25))&&((read_insertion_array[j].length==simulate_insertion_array[i].length)))){
			  	fprintf(write_insertion,"%ld\t%ld\t%ld\n",read_insertion_array[j].start,read_insertion_array[j].end,read_insertion_array[j].length);
			  }
		}
	}

    //deletion operation
    long int s_d_count=0;
   while(!feof(simulate_deletion)){
   	if((fgets(line,1024,simulate_deletion))!=NULL) s_d_count++;
   }
   sv *simulate_deletion_array=(sv*)malloc(sizeof(sv)*s_d_count);
   rewind(simulate_deletion);
   s_d_count=0;
   while(!feof(simulate_deletion)){
   	if((fgets(line,1024,simulate_deletion))!=NULL){
   		char *delim="\t";
   		char *p=strtok(line,delim);
   		int c=0;
   		long int a[3];
   		while(p!=NULL){ 
			a[c]=strtol(p,NULL,10);
			c++;
            p=strtok(NULL,delim); 
           }
           simulate_deletion_array[s_d_count].start=a[0];
           simulate_deletion_array[s_d_count].end=a[1];
           simulate_deletion_array[s_d_count].length=a[2];
           s_d_count++;
		}
   }
    long int r_d_count=0;
   while(!feof(read_deletion)){
   	if((fgets(line,1024,read_deletion))!=NULL) r_d_count++;
   }
   sv *read_deletion_array=(sv*)malloc(sizeof(sv)*r_d_count);
   rewind(read_deletion);
   r_d_count=0;
   fgets(line,1024,read_deletion);
   while(!feof(read_deletion)){ 
	        fgets(line,1024,read_deletion);
			char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
			int num_i=0;
			long int r_a[3];
            while(p!=NULL){ 
			  if(num==2||num==3||num==4) {
			     r_a[num_i]=strtol(p,NULL,10);
			     num_i++;
			  }
			num++;
            p=strtok(NULL,delim); 
           }
           read_deletion_array[r_d_count].start=r_a[0];
           read_deletion_array[r_d_count].end=r_a[1];
           read_deletion_array[r_d_count].length=r_a[2];
           r_d_count++;
		   //fprintf(write_deletion,"%s","\n");  
		   } 
	for(long int i=0;i<s_d_count;i++){
		for(long int j=0;j<r_d_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((read_deletion_array[j].start>=(simulate_deletion_array[i].start-25))&&(read_deletion_array[j].start<=(simulate_deletion_array[i].start+25)))
			  ||((read_deletion_array[j].end>=(simulate_deletion_array[i].end-25))&&(read_deletion_array[j].end<=(simulate_deletion_array[i].end+25))&&((read_deletion_array[j].length==simulate_deletion_array[i].length)))){
			  	fprintf(write_deletion,"%ld\t%ld\t%ld\n",read_deletion_array[j].start,read_deletion_array[j].end,read_deletion_array[j].length);
			  }
		}
	}
   
	//inversion operation
	 long int s_count=0;
   while(!feof(simulate_inversion)){
   	if((fgets(line,1024,simulate_inversion))!=NULL) s_count++;
   }
   sv *simulate_inversion_array=(sv*)malloc(sizeof(sv)*s_count);
   rewind(simulate_inversion);
   s_count=0;
   while(!feof(simulate_inversion)){
   	if((fgets(line,1024,simulate_inversion))!=NULL){
   		char *delim="\t";
   		char *p=strtok(line,delim);
   		int c=0;
   		long int a[3];
   		while(p!=NULL){ 
			a[c]=strtol(p,NULL,10);
			c++;
            p=strtok(NULL,delim); 
           }
           simulate_inversion_array[s_count].start=a[0];
           simulate_inversion_array[s_count].end=a[1];
           simulate_inversion_array[s_count].length=a[2];
           s_count++;
		}
   }
    long int inv_count=0;
   while(!feof(read_inversion)){
   	if((fgets(line,1024,read_inversion))!=NULL) inv_count++;
   }
   sv *read_inversion_array=(sv*)malloc(sizeof(sv)*inv_count);
   rewind(read_inversion);
   inv_count=0;
   fgets(line,1024,read_inversion);
   while(!feof(read_inversion)){ 
	        fgets(line,1024,read_inversion);
			char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
			int num_i=0;
			long int r_a[3];
            while(p!=NULL){ 
			  if(num==2||num==3||num==4) {
			     r_a[num_i]=strtol(p,NULL,10);
			     num_i++;
			  }
			num++;
            p=strtok(NULL,delim); 
           }
           read_inversion_array[inv_count].start=r_a[0];
           read_inversion_array[inv_count].end=r_a[1];
           read_inversion_array[inv_count].length=r_a[2];
           inv_count++;
		   //fprintf(write_inversion,"%s","\n");  
		   } 
	for(long int i=0;i<s_d_count;i++){
		for(long int j=0;j<inv_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((read_inversion_array[j].start>=(simulate_inversion_array[i].start-25))&&(read_inversion_array[j].start<=(simulate_inversion_array[i].start+25)))
			  ||((read_inversion_array[j].end>=(simulate_inversion_array[i].end-25))&&(read_inversion_array[j].end<=(simulate_inversion_array[i].end+25))&&((read_inversion_array[j].length==simulate_inversion_array[i].length)))){
			  	fprintf(write_inversion,"%ld\t%ld\t%ld\n",read_inversion_array[j].start,read_inversion_array[j].end,read_inversion_array[j].length);
			  }
		}
	}
   
		   
	free(read_insertion_array);
	free(read_deletion_array);
	free(read_inversion_array);
	free(simulate_insertion_array);
	free(simulate_deletion_array);
	free(simulate_inversion_array);	   
    fclose(read_insertion);
    fclose(read_deletion);
    fclose(read_inversion);
    fclose(simulate_insertion);
    fclose(simulate_deletion);
    fclose(simulate_inversion);
    fclose(write_insertion);
    fclose(write_deletion);
    fclose(write_inversion);
	return 0;
 } 
