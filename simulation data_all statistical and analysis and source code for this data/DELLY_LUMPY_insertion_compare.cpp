#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************** 
function:lumpy and delly share the number of insertions in simulation data 
running Operating System: Windows Server 10   
compiler: Dev-c++-5.11 64-bit
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
	FILE *lumpy_data,*delly_data,*total_file;
	/* 
	if((simulate_data=fopen("F://data//similation_insertion.txt","r"))==NULL){
		puts("simulate data can not open.");
		exit(0);
	}
	*/ 
	if((lumpy_data=fopen("F://data//simulation//lumpy//insertion.txt","r"))==NULL){
		puts("lumpy data file can not open.");
		exit(0);
	}
	
	if((delly_data=fopen("F://data//simulation//delly//insertion.txt","r"))==NULL){
		puts("DELLY data file can not open.");
		exit(0);
	}
	
	
	if((total_file=fopen("F://data//simulation//DL_total_insertion.txt","w+"))==NULL){
		puts("DL_total_insertion can not open.");
		exit(0);
	} 
	
	
	
	//extract file
	char line[1024];
	long int a[3];
	long int simulate_count=0;
	long int lumpy_count=0;
	long int delly_count=0;
//	long int lumpy_count=0;

	while(fgets(line,1024,lumpy_data)!=NULL){
		//if()
		  lumpy_count++;
		
	}
	//printf("lumpy_count=%ld\n",lumpy_count);
	rewind(lumpy_data);
	sv *lumpy_array=(sv*)malloc(lumpy_count*sizeof(sv));
	while(fgets(line,1024,delly_data)!=NULL){
		//if()
		  delly_count++;
		
	}
	//printf("lumpy_count=%ld\n",lumpy_count);
	rewind(delly_data);
	sv *delly_array=(sv*)malloc(delly_count*sizeof(sv));

	//printf("lumpy_count=%ld\n",lumpy_count);
//	rewind(lumpy_data);
	//sv *lumpy_array=(sv*)malloc(lumpy_count*sizeof(sv));
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
			
	while(fgets(line,1024,lumpy_data)!=NULL){ 
            
            char *delim= "\t";
            char *p=strtok(line,delim);
			int num=0; 
            while(p!=NULL){ 
			   a[num]=strtol(p,NULL,10);
               p=strtok(NULL,delim); 
               num++;	
			}//(p!=NULL)
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,a[0],a[1],a[2]);
           lumpy_array[p_i].start=a[0];
           lumpy_array[p_i].end=a[1];
           lumpy_array[p_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,lumpy_array[p_i].start,lumpy_array[p_i].end,lumpy_array[p_i].length);
           p_i++;
         
		}//while(!feof(lumpy_data))
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
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,lumpy_array[p_i].start,lumpy_array[p_i].end,lumpy_array[p_i].length);
           d_i++;
         
		}//while(!feof(lumpy_data))  
		
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
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,lumpy_array[p_i].start,lumpy_array[p_i].end,lumpy_array[p_i].length);
           l_i++;
         
		}//while(!feof(lumpy_data)) 
		*/
		
		//insertion 
		long int insertion_1=0;
		long int insertion_100=0;
		long int insertion_200=0;
		/* 
		for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<delly_count;j++){
			for(long int z=0;j<lumpy_count;z++){
			
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[i].start>=(delly_array[j].start-25))&&(lumpy_array[i].start<=(delly_array[j].start+25))
			&&(lumpy_array[i].start>=(lumpy_array[z].start-25))&&(lumpy_array[i].start<=(lumpy_array[z].start+25))
			&&(delly_array[j].start>=(lumpy_array[z].start-25))&&(delly_array[j].start<=(lumpy_array[z].start+25))
			&&((lumpy_array[j].length==delly_array[i].length==lumpy_array[z].length)))
			||((lumpy_array[i].end>=(delly_array[j].end-25))&&(lumpy_array[i].end<=(delly_array[j].end+25))
			&&(lumpy_array[i].end>=(lumpy_array[z].end-25))&&(lumpy_array[i].end<=(delly_array[z].end+25))
			&&(lumpy_array[z].end>=(delly_array[i].end-25))&&(lumpy_array[z].end<=(delly_array[i].end+25))
			&&((lumpy_array[j].length==delly_array[i].length)==lumpy_array[z].length))){
			  	fprintf(analysis_lumpy,"%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
				if((lumpy_array[j].length>=1)&&(lumpy_array[j].length<=99)) insertion_1++;
			  	if((lumpy_array[j].length>=100)&&(lumpy_array[j].length<=199)) insertion_100++;
			  	if((lumpy_array[j].length>=200)&&(lumpy_array[j].length<=300)) insertion_200++;
			  }
		}
	}
}
*/ 
//fprintf(total_file,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
		//||((lumpy_array[j].length>=(simulate_array[i].length-25))&&(lumpy_array[j].length<=(simulate_array[i].length+25))) 

	for(long int i=0;i<delly_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(delly_array[i].start-25))&&(lumpy_array[j].start<=(delly_array[i].start+25))&&((lumpy_array[j].length==delly_array[i].length)))
			  ||((lumpy_array[j].end>=(delly_array[i].end-25))&&(lumpy_array[j].end<=(delly_array[i].end+25))&&((lumpy_array[j].length==delly_array[i].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
				if((lumpy_array[j].length>=1)&&(lumpy_array[j].length<=99)) insertion_1++;
			  	if((lumpy_array[j].length>=100)&&(lumpy_array[j].length<=199)) insertion_100++;
			  	if((lumpy_array[j].length>=200)&&(lumpy_array[j].length<=300)) insertion_200++;
			  }
		}
	}
	fprintf(total_file,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
	/* 
	fprintf(analysis_lumpy,"length(1bp-99bp):%ld\nlength(100bp-199bp):%ld\nlength(200-300bp):%ld\n",insertion_1,insertion_100,insertion_200);
	
	    long int d_insertion_1=0;
		long int d_insertion_100=0;
		long int d_insertion_200=0;
		//||((lumpy_array[j].length>=(simulate_array[i].length-25))&&(lumpy_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<delly_count;j++){
				//printf("%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			if(((delly_array[j].start>=(lumpy_array[i].start-25))&&(delly_array[j].start<=(lumpy_array[i].start+25))&&((delly_array[j].length==lumpy_array[i].length)))
			  ||((delly_array[j].end>=(lumpy_array[i].end-25))&&(delly_array[j].end<=(lumpy_array[i].end+25))&&((delly_array[j].length==lumpy_array[i].length)))){
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
	
	for(long int i=0;i<delly_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(delly_array[i].start-25))&&(lumpy_array[j].start<=(delly_array[i].start+25))&&((lumpy_array[j].length==delly_array[i].length)))
			  ||((lumpy_array[j].end>=(delly_array[i].end-25))&&(lumpy_array[j].end<=(delly_array[i].end+25))&&((lumpy_array[j].length==delly_array[i].length)))){
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
	fclose(lumpy_data);
	fclose(delly_data);
	//fclose(lumpy_data);
//	fclose(analysis_lumpy);
	//fclose(analysis_delly);
	//fclose(analysis_lumpy);
	puts("finish.");
	return 0;
 } 
