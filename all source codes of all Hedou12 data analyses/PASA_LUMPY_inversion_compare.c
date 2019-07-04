#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************** 
function:PASA and lumpy share the number of inversions in hedou data. 
running Operating System: Windows Server 10   
compiler: Dev-c++-5.11 64-bit
*************************************************************************/ 
typedef struct struc_sv{
	long int start;
	long int end;
	long int length;
}sv;

static int compare_int(const void *int1, const void *int2) {

   if (*(const int *)int1 > *(const int *)int2)
         return 1;
   else if (*(const int *)int1 < *(const int *)int2)
         return -1;
   else
         return 0;

}

static int partition(void *data, int esize, int i, int k, int (*compare)

   (const void *key1, const void *key2)) {



char               *a = data;

void               *pval, *temp;

int                r[3];

if ((pval = malloc(esize)) == NULL)

   return -1;
if ((temp = malloc(esize)) == NULL) {
   free(pval);

   return -1;
}

r[0] = (rand() % (k - i + 1)) + i;

r[1] = (rand() % (k - i + 1)) + i;

r[2] = (rand() % (k - i + 1)) + i;

issort(r, 3, sizeof(int), compare_int);
memcpy(pval, &a[r[1] * esize], esize);

i--;

k++;

while (1) {
   do {
      k--;
   } while (compare(&a[k * esize], pval) > 0);

   do {



      i++;

   } while (compare(&a[i * esize], pval) < 0);
   if (i >= k) {


      break;

      } else {
      memcpy(temp, &a[i * esize], esize);

      memcpy(&a[i * esize], &a[k * esize], esize);

      memcpy(&a[k * esize], temp, esize);
   }



}

   free(pval);

  free(temp);

  return k;

}

int qksort(void *data, int size, int esize, int i, int k, int (*compare)

   (const void *key1, const void *key2)) {

int                j;
if (i < k) {
   if ((j = partition(data, esize, i, k, compare)) < 0)

      return -1;

   if (qksort(data, size, esize, i, j, compare) < 0)

      return -1;

   if (qksort(data, size, esize, j + 1, k, compare) < 0)

      return -1;

}
 return 0;
}


static int compare_str(const void *str1, const void *str2) {

     int                retval;
      if ((retval = strcmp((const char *)str1, (const char *)str2)) > 0)
          return 1;
      else if (retval < 0)
         return -1;
      else
         return 0;

}

int issort(void *data, int size, int esize, int (*compare)(const void *key1,
   const void *key2)) {

    char   *a = data;

    void   *key;

       int  i, j;

if ((key = (char *)malloc(esize)) == NULL)
   return -1;
for (j = 1; j < size; j++) {

   memcpy(key, &a[j * esize], esize);
   i = j - 1;

   while (i >= 0 && compare(&a[i * esize], key) > 0) {

      memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
      i--;

   }

   memcpy(&a[(i + 1) * esize], key, esize);

}


free(key);

return 0;

}





int main(void)
{
	puts("start");
	puts("....");
	FILE *simulate_data,*pasa_data,*delly_data,*lumpy_data,*analysis_pasa,*analysis_delly,*analysis_lumpy,*total_file;
	/*
	if((simulate_data=fopen("F://data//similation//inversion.txt","r"))==NULL){
		puts("simulate data can not open.");
		exit(0);
	}
	*/
	if((pasa_data=fopen("F://data//hedou//pasa//inversion.txt","r"))==NULL){
		puts("PASA data file can not open.");
		exit(0);
	}
	/* 
	if((delly_data=fopen("F://data//simulation//delly//inversion.txt","r"))==NULL){
		puts("DELLY data file can not open.");
		exit(0);
	}
	*/ 
	if((lumpy_data=fopen("F://data//hedou//lumpy//inversion.txt","r"))==NULL){
		puts("LUMPY data file can not open.");
		exit(0);
	}
	/* 
	if((analysis_delly=fopen("F://data//simulation///delly_analysis_inversion.txt","w+"))==NULL){
		puts("delly_analysis_inversion can not open.");
		exit(0);
	}
	/* 
	if((analysis_lumpy=fopen("F://data//simulation//umpy_analysis_inversion.txt","w+"))==NULL){
		puts("lumpy_analysis_insertion can not open.");
		exit(0);
	}
	*/
	/* 
	if((analysis_pasa=fopen("F://data//pasa_analysis_inversion.txt","w+"))==NULL){
		puts("pasa_analysis_inversion can not open.");
		exit(0);
	} 
	*/ 
	if((total_file=fopen("F://data//hedou//pl_total_inversion.txt","w+"))==NULL){
		puts("pl_total_inversion can not open.");
		exit(0);
	} 
	//extract file
	char line[1024];
	long int a[3];
	long int simulate_count=0;
	long int pasa_count=0;
	long int delly_count=0;
	long int lumpy_count=0;
	/*
	while(fgets(line,1024,simulate_data)!=NULL){
	//	if()
		  simulate_count++;
	}
	//printf("simulate_count=%ld\n",simulate_count);
    rewind(simulate_data); 
    */
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
		long int inversion_1=0;
		long int inversion_500=0;
		long int inversion_1000=0;
		long int inversion_2000=0;
		long int inversion_3000=0;
		long int inversion_4000=0;
		long int inversion_5000=0;
		long int inversion_6000=0;
		/* 
		for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<pasa_count;j++){
			for(long int z=0;z<delly_count;z++){
			
				//printf("%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			if(((pasa_array[j].start>=(lumpy_array[i].start-25))&&(pasa_array[j].start<=(lumpy_array[i].start+25))
			 &&(pasa_array[j].start>=(delly_array[z].start-25))&&(pasa_array[j].start<=(delly_array[z].start+25))
			 &&(delly_array[z].start>=(lumpy_array[i].start-25))&&(delly_array[z].start<=(lumpy_array[i].start+25))
			 &&((pasa_array[j].length==lumpy_array[i].length)==delly_array[z].length))
			||((pasa_array[j].end>=(lumpy_array[i].end-25))&&(pasa_array[j].end<=(lumpy_array[i].end+25))
			&&(delly_array[z].end>=(lumpy_array[i].end-25))&&(delly_array[z].end<=(lumpy_array[i].end+25))
			&&(pasa_array[j].end>=(delly_array[z].end-25))&&(pasa_array[j].end<=(delly_array[z].end+25))
			&&((pasa_array[j].length==lumpy_array[i].length==delly_array[z].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
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
		
	}
	
	
		fprintf(total_file,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   inversion_1,inversion_500,inversion_1000,inversion_2000,inversion_3000,inversion_4000,inversion_5000,inversion_6000);
		
		*/ 
		 inversion_1=0;
	     inversion_500=0;
		 inversion_1000=0;
		 inversion_2000=0;
		 inversion_3000=0;
		 inversion_4000=0;
		 inversion_5000=0;
		 inversion_6000=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	
	for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<pasa_count;j++){
				//printf("%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
			if(((pasa_array[j].start>=(lumpy_array[i].start-35))&&(pasa_array[j].start<=(lumpy_array[i].start+35))&&((pasa_array[j].length==lumpy_array[i].length)))
			  ||((pasa_array[j].end>=(lumpy_array[i].end-35))&&(pasa_array[j].end<=(lumpy_array[i].end+35))&&((pasa_array[j].length==lumpy_array[i].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",pasa_array[j].start,pasa_array[j].end,pasa_array[j].length);
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
	fprintf(total_file,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   inversion_1,inversion_500,inversion_1000,inversion_2000,inversion_3000,inversion_4000,inversion_5000,inversion_6000);
	/*
	fprintf(analysis_pasa,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   inversion_1,inversion_500,inversion_1000,inversion_2000,inversion_3000,inversion_4000,inversion_5000,inversion_6000);
	
	    long int d_inversion_1=0;
		long int d_inversion_500=0;
		long int d_inversion_1000=0;
		long int d_inversion_2000=0;
		long int d_inversion_3000=0;
		long int d_inversion_4000=0;
		long int d_inversion_5000=0;
		long int d_inversion_6000=0;
		//||((pasa_array[j].length>=(simulate_array[i].length-25))&&(pasa_array[j].length<=(simulate_array[i].length+25))) 
	for(long int i=0;i<pasa_count;i++){
		for(long int j=0;j<delly_count;j++){
				//printf("%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			if(((delly_array[j].start>=(pasa_array[i].start-20))&&(delly_array[j].start<=(pasa_array[i].start+20))&&((delly_array[j].length==pasa_array[i].length)))
			  ||((delly_array[j].end>=(pasa_array[i].end-20))&&(delly_array[j].end<=(pasa_array[i].end+20))&&((delly_array[j].length==pasa_array[i].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
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
	*/
//	fprintf(total_file,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
//						   d_inversion_1,d_inversion_500,d_inversion_1000,d_inversion_2000,d_inversion_3000,d_inversion_4000,d_inversion_5000,d_inversion_6000);
						   
	    long int l_inversion_1=0;
		long int l_inversion_500=0;
		long int l_inversion_1000=0;
		long int l_inversion_2000=0;
		long int l_inversion_3000=0;
		long int l_inversion_4000=0;
		long int l_inversion_5000=0;
		long int l_inversion_6000=0;
	/* 
	for(long int i=0;i<delly_count;i++){
		for(long int j=0;j<lumpy_count;j++){
				//printf("%ld\t%ld\t%ld\n",lumpy_array[j].start,lumpy_array[j].end,lumpy_array[j].length);
			if(((lumpy_array[j].start>=(delly_array[i].start-25))&&(lumpy_array[j].start<=(delly_array[i].start+25))&&((lumpy_array[j].length==delly_array[i].length)))
			  ||((lumpy_array[j].end>=(delly_array[i].end-25))&&(lumpy_array[j].end<=(delly_array[i].end+25))&&((lumpy_array[j].length==delly_array[i].length)))){
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
	
	*/
	//fclose(simulate_data);
	fclose(pasa_data);
	//fclose(delly_data);
	fclose(lumpy_data);
	//fclose(analysis_pasa);
	//fclose(analysis_delly);
	//fclose(analysis_lumpy);
	fclose(total_file);
	puts("finish.");
	return 0;
 } 
