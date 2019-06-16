#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/****************************************************************************** 
function:compare PASA with delly and lumpy,separately. compare thier deletion. 


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
	if((simulate_data=fopen("F://data//simulate_inversion.txt","r"))==NULL){
		puts("simulate data can not open.");
		exit(0);
	}
	if((pasa_data=fopen("F://data//PASA_inversion.txt","r"))==NULL){
		puts("PASA data file can not open.");
		exit(0);
	}
	
	if((delly_data=fopen("F://data//DELLY_inversion.txt","r"))==NULL){
		puts("DELLY data file can not open.");
		exit(0);
	}
	if((lumpy_data=fopen("F://data//LUMPY_inversion.txt","r"))==NULL){
		puts("LUMPY data file can not open.");
		exit(0);
	}
	if((analysis_delly=fopen("F://data//delly_analysis_inversion.txt","w+"))==NULL){
		puts("delly_analysis_insertion can not open.");
		exit(0);
	}
	if((analysis_lumpy=fopen("F://data//lumpy_analysis_inversion.txt","w+"))==NULL){
		puts("lumpy_analysis_insertion can not open.");
		exit(0);
	}
	if((analysis_pasa=fopen("F://data//pasa_analysis_inversion.txt","w+"))==NULL){
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
		long int inversion_1=0;
		long int inversion_500=0;
		long int inversion_1000=0;
		long int inversion_2000=0;
		long int inversion_3000=0;
		long int inversion_4000=0;
		long int inversion_5000=0;
		long int inversion_6000=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<simulate_count;i++){
		for(long int j=0;j<pasa_count;j++){
				//printf("%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			if(((pasa_array[j].start>=(simulate_array[i].start-25))&&(pasa_array[j].start<=(simulate_array[i].start+25))&&((pasa_array[j].length==simulate_array[i].length)))
			  ||((pasa_array[j].end>=(simulate_array[i].end-25))&&(pasa_array[j].end<=(simulate_array[i].end+25))&&((pasa_array[j].length==simulate_array[i].length)))){
			  	fprintf(analysis_pasa,"%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			 if((pasa_array[j].length>=1)&&(pasa_array[j].length<=499)) inversion_1++;
			  	if((pasa_array[j].length>=500)&&(pasa_array[j].length<=999)) inversion_500++;
			  	if((pasa_array[j].length>=1000)&&(pasa_array[j].length<=1999)) inversion_1000++;
			  	if((pasa_array[j].length>=2000)&&(pasa_array[j].length<=2999)) inversion_2000++;
			  	if((pasa_array[j].length>=3000)&&(pasa_array[j].length<=3999)) inversion_3000++;
			  	if((pasa_array[j].length>=4000)&&(pasa_array[j].length<=4999)) inversion_4000++;
			  	if((pasa_array[j].length>=5000)&&(pasa_array[j].length<=5999)) inversion_5000++;
			  	if(pasa_array[j].length>=6000) inversion_6000++;
			  }
		}
	}
	fprintf(analysis_pasa,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   inversion_1,inversion_500,inversion_1000,inversion_2000,inversion_3000,inversion_4000,inversion_5000,inversion_6000);
	//delly
	     long int d_inversion_1=0;
		long int d_inversion_500=0;
		long int d_inversion_1000=0;
		long int d_inversion_2000=0;
		long int d_inversion_3000=0;
		long int d_inversion_4000=0;
		long int d_inversion_5000=0;
		long int d_inversion_6000=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<simulate_count;i++){
		for(long int j=0;j<delly_count;j++){
				//printf("%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			if(((delly_array[j].start>=(simulate_array[i].start-25))&&(delly_array[j].start<=(simulate_array[i].start+25))&&((delly_array[j].length==simulate_array[i].length)))
			  ||((delly_array[j].end>=(simulate_array[i].end-25))&&(delly_array[j].end<=(simulate_array[i].end+25))&&((delly_array[j].length==simulate_array[i].length)))){
			  	fprintf(analysis_delly,"%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
				if((delly_array[j].length>=1)&&(delly_array[j].length<=499)) d_inversion_1++;
			  	if((delly_array[j].length>=500)&&(delly_array[j].length<=999)) d_inversion_500++;
			  	if((delly_array[j].length>=1000)&&(delly_array[j].length<=1999)) d_inversion_1000++;
			  	if((delly_array[j].length>=2000)&&(delly_array[j].length<=2999)) d_inversion_2000++;
			  	if((delly_array[j].length>=3000)&&(delly_array[j].length<=3999)) d_inversion_3000++;
			  	if((delly_array[j].length>=4000)&&(delly_array[j].length<=4999)) d_inversion_4000++;
			  	if((delly_array[j].length>=5000)&&(delly_array[j].length<=5999)) d_inversion_5000++;
			  	if(delly_array[j].length>=6000) d_inversion_6000++;
			  }
		}
	}
	fprintf(analysis_delly,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   d_inversion_1,d_inversion_500,d_inversion_1000,d_inversion_2000,d_inversion_3000,d_inversion_4000,d_inversion_5000,d_inversion_6000);
	//lumpy					   
	    long int l_inversion_1=0;
		long int l_inversion_500=0;
		long int l_inversion_1000=0;
		long int l_inversion_2000=0;
		long int l_inversion_3000=0;
		long int l_inversion_4000=0;
		long int l_inversion_5000=0;
		long int l_inversion_6000=0;
	
	for(long int i=0;i<simulate_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(simulate_array[i].start-25))&&(lumpy_array[j].start<=(simulate_array[i].start+25))&&((lumpy_array[j].length==simulate_array[i].length)))
			  ||((lumpy_array[j].end>=(simulate_array[i].end-25))&&(lumpy_array[j].end<=(simulate_array[i].end+25))&&((lumpy_array[j].length==simulate_array[i].length)))){
			  	fprintf(analysis_lumpy,"%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
				if((lumpy_array[j].length>=1)&&(lumpy_array[j].length<=499)) l_inversion_1++;
			  	if((lumpy_array[j].length>=500)&&(lumpy_array[j].length<=999)) l_inversion_500++;
			  	if((lumpy_array[j].length>=1000)&&(lumpy_array[j].length<=1999)) l_inversion_1000++;
			  	if((lumpy_array[j].length>=2000)&&(lumpy_array[j].length<=2999)) l_inversion_2000++;
			  	if((lumpy_array[j].length>=3000)&&(lumpy_array[j].length<=3999)) l_inversion_3000++;
			  	if((lumpy_array[j].length>=4000)&&(lumpy_array[j].length<=4999)) l_inversion_4000++;
			  	if((lumpy_array[j].length>=5000)&&(lumpy_array[j].length<=5999)) l_inversion_5000++;
			  	if(lumpy_array[j].length>=6000) l_inversion_6000++;
			  }
		}
	}
	fprintf(analysis_lumpy,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   l_inversion_1,l_inversion_500,l_inversion_1000,l_inversion_2000,l_inversion_3000,l_inversion_4000,l_inversion_5000,l_inversion_6000);
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
