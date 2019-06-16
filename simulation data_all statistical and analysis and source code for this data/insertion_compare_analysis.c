#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************** 
function:compare PASA with delly and lumpy,separately. compare their insertion
running Operating System: Windows Server 10   
compiler£ºTDM-GCC 4.9.2 64-bit
*************************************************************************/ 

typedef struct struc_sv{
	long int start;
	long int end;
	long int length;
}sv;
int main(void)
{
	puts("start");
	puts("....");
	FILE *simulate_data,*pasa_data,*delly_data,*lumpy_data,*analysis_pasa,*analysis_delly,*analysis_lumpy;
	if((simulate_data=fopen("F://data//similation_insertion.txt","r"))==NULL){
		puts("simulate data can not open.");
		exit(0);
	}
	if((pasa_data=fopen("F://data//extract_PASA_insertion.txt","r"))==NULL){
		puts("PASA data file can not open.");
		exit(0);
	}
	
	if((delly_data=fopen("F://data//extract_DELLY_insertion.txt","r"))==NULL){
		puts("DELLY data file can not open.");
		exit(0);
	}
	if((lumpy_data=fopen("F://data//extract_LUMPY_insertion.txt","r"))==NULL){
		puts("LUMPY data file can not open.");
		exit(0);
	}
	if((analysis_delly=fopen("F://data//delly_analysis_insertion.txt","w+"))==NULL){
		puts("delly_analysis_insertion can not open.");
		exit(0);
	}
	if((analysis_lumpy=fopen("F://data//lumpy_analysis_insertion.txt","w+"))==NULL){
		puts("lumpy_analysis_insertion can not open.");
		exit(0);
	}
	if((analysis_pasa=fopen("F://data//pasa_analysis_insertion.txt","w+"))==NULL){
		puts("pasa_analysis_insertion can not open.");
		exit(0);
	} 
	
	//extract file
	char line[1024];
	long int a[3];
	long int simulate_count=0;
	long int pasa_count=0;
	long int delly_count=0;
	long int lumpy_count=0;
	while(fgets(line,1024,simulate_data)!=NULL){
	//	if()
		  simulate_count++;
	}
	//printf("simulate_count=%ld\n",simulate_count);
    rewind(simulate_data); 
	sv *simulate_array=(sv*)malloc(simulate_count*sizeof(sv));
	while(fgets(line,1024,pasa_data)!=NULL){
		//if()
		  pasa_count++;
		
	}
	//printf("pasa_count=%ld\n",pasa_count);
	rewind(pasa_data);
	sv *pasa_array=(sv*)malloc(pasa_count*sizeof(sv));
	while(fgets(line,1024,delly_data)!=NULL){
		//if()
		  delly_count++;
		
	}
	//printf("pasa_count=%ld\n",pasa_count);
	rewind(delly_data);
	sv *delly_array=(sv*)malloc(delly_count*sizeof(sv));
	while(fgets(line,1024,lumpy_data)!=NULL){
		//if()
		  lumpy_count++;
		
	}
	//printf("pasa_count=%ld\n",pasa_count);
	rewind(lumpy_data);
	sv *lumpy_array=(sv*)malloc(lumpy_count*sizeof(sv));
	long int s_i=0;
	long int p_i=0;
	long int d_i=0;
	long int l_i=0;
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
			
	while(fgets(line,1024,pasa_data)!=NULL){ 
            
            char *delim="\t";
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
	while(fgets(line,1024,delly_data)!=NULL){ 
            
            char *delim="\t";
            char *p=strtok(line,delim);
			int num=0; 
            while(p!=NULL){ 
			   a[num]=strtol(p,NULL,10);
               p=strtok(NULL,delim); 
               num++;	
			}//(p!=NULL)
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,a[0],a[1],a[2]);
           delly_array[d_i].start=a[0];
           delly_array[d_i].end=a[1];
           delly_array[d_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,pasa_array[p_i].start,pasa_array[p_i].end,pasa_array[p_i].length);
           d_i++;
         
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
           lumpy_array[l_i].start=a[0];
           lumpy_array[l_i].end=a[1];
           lumpy_array[l_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,pasa_array[p_i].start,pasa_array[p_i].end,pasa_array[p_i].length);
           l_i++;
         
		}//while(!feof(pasa_data)) 
		
		//insertion 
		long int insertion_1=0;
		long int insertion_100=0;
		long int insertion_200=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<simulate_count;i++){
		for(long int j=0;j<pasa_count;j++){
				//printf("%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			if(((pasa_array[j].start>=(simulate_array[i].start-25))&&(pasa_array[j].start<=(simulate_array[i].start+25))&&((pasa_array[j].length==simulate_array[i].length)))
			  ||((pasa_array[j].end>=(simulate_array[i].end-25))&&(pasa_array[j].end<=(simulate_array[i].end+25))&&((pasa_array[j].length==simulate_array[i].length)))){
			  	fprintf(analysis_pasa,"%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
				if((pasa_array[j].length>=1)&&(pasa_array[j].length<=99)) insertion_1++;
			  	if((pasa_array[j].length>=100)&&(pasa_array[j].length<=199)) insertion_100++;
			  	if((pasa_array[j].length>=200)&&(pasa_array[j].length<=300)) insertion_200++;
			  }
		}
	}
	fprintf(analysis_pasa,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
	
	    long int d_insertion_1=0;
		long int d_insertion_100=0;
		long int d_insertion_200=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<simulate_count;i++){
		for(long int j=0;j<delly_count;j++){
				//printf("%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			if(((delly_array[j].start>=(simulate_array[i].start-25))&&(delly_array[j].start<=(simulate_array[i].start+25))&&((delly_array[j].length==simulate_array[i].length)))
			  ||((delly_array[j].end>=(simulate_array[i].end-25))&&(delly_array[j].end<=(simulate_array[i].end+25))&&((delly_array[j].length==simulate_array[i].length)))){
			  	fprintf(analysis_delly,"%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
				if((delly_array[j].length>=1)&&(delly_array[j].length<=99)) d_insertion_1++;
			  	if((delly_array[j].length>=100)&&(delly_array[j].length<=199)) d_insertion_100++;
			  	if((delly_array[j].length>=200)&&(delly_array[j].length<=300)) d_insertion_200++;
			  }
		}
	}
	fprintf(analysis_delly,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",d_insertion_1,d_insertion_100,d_insertion_200);
	    long int l_insertion_1=0;
		long int l_insertion_100=0;
		long int l_insertion_200=0;
	
	for(long int i=0;i<simulate_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(simulate_array[i].start-25))&&(lumpy_array[j].start<=(simulate_array[i].start+25))&&((lumpy_array[j].length==simulate_array[i].length)))
			  ||((lumpy_array[j].end>=(simulate_array[i].end-25))&&(lumpy_array[j].end<=(simulate_array[i].end+25))&&((lumpy_array[j].length==simulate_array[i].length)))){
			  	fprintf(analysis_lumpy,"%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
				if((lumpy_array[j].length>=1)&&(lumpy_array[j].length<=99)) l_insertion_1++;
			  	if((lumpy_array[j].length>=100)&&(lumpy_array[j].length<=199)) l_insertion_100++;
			  	if((lumpy_array[j].length>=200)&&(lumpy_array[j].length<=300)) l_insertion_200++;
			  }
		}
	}
	fprintf(analysis_lumpy,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",l_insertion_1,l_insertion_100,l_insertion_200);
	fclose(simulate_data);
	fclose(pasa_data);
	fclose(delly_data);
	fclose(lumpy_data);
	fclose(analysis_pasa);
	fclose(analysis_delly);
	fclose(analysis_lumpy);
	puts("finish.");
	return 0;
 } 
