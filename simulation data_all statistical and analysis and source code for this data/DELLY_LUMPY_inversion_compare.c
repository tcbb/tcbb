#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************** 
function:delly and lumpy share the number of inversions in hedou12 data. 
running Operating System: Windows Server 10   
compiler: Dev-c++-5.11 64-bit
*************************************************************************/ 
typedef struct struc_sv{
	long int start;
	long int end;
	long int length;
}sv;



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

static int compare_str(const void *str1, const void *str2) {

     int                retval;
      if ((retval = strcmp((const char *)str1, (const char *)str2)) > 0)
          return 1;
      else if (retval < 0)
         return -1;
      else
         return 0;

}

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



void               *pval,

                   *temp;

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
static int merge(void *data, int esize, int i, int j, int k, int (*compare)
   (const void *key1, const void *key2)) {

      char               *a = data, *m;

      int                ipos,jpos, mpos;


      ipos = i;
      jpos = j + 1;
      mpos = 0;


     if ((m = (char *)malloc(esize * ((k - i) + 1))) == NULL)
        return -1;


     while (ipos <= j || jpos <= k) {

   if (ipos > j) {

      while (jpos <= k) {

         memcpy(&m[mpos * esize], &a[jpos * esize], esize);
         jpos++;
         mpos++;
      }
      continue;
      }

   else if (jpos > k) {

      while (ipos <= j) {

         memcpy(&m[mpos * esize], &a[ipos * esize], esize);
         ipos++;
         mpos++;

      }

      continue;

   }


   if (compare(&a[ipos * esize], &a[jpos * esize]) < 0) {

      memcpy(&m[mpos * esize], &a[ipos * esize], esize);
      ipos++;
      mpos++;

      }

   else {

      memcpy(&m[mpos * esize], &a[jpos * esize], esize);
      jpos++;
      mpos++;

   }

}

memcpy(&a[i * esize], m, esize * ((k - i) + 1));


free(m);

return 0;

}


int mgsort(void *data, int size, int esize, int i, int k, int (*compare)
   (const void *key1, const void *key2)) {

    int                j;



   if (i < k) {
      j = (int)(((i + k - 1)) / 2);


     if (mgsort(data, size, esize, i, j, compare) < 0)
      return -1;

     if (mgsort(data, size, esize, j + 1, k, compare) < 0)
      return -1;


   if (merge(data, esize, i, j, k, compare) < 0)
      return -1;

}

return 0;

}


int main(void)
{
	puts("start");
	puts("....");
	FILE *delly_data,*lumpy_data,*analysis_delly,*analysis_lumpy,*total_file;

	
	if((delly_data=fopen("F://data//hedou//delly//inversion.txt","r"))==NULL){
		puts("DELLY data file can not open.");
		exit(0);
	}
	
	if((lumpy_data=fopen("F://data//hedou//lumpy//inversion.txt","r"))==NULL){
		puts("LUMPY data file can not open.");
		exit(0);
	}
	
	if((total_file=fopen("F://data//hedou//dl_total_inversion.txt","w+"))==NULL){
		puts("dl_total_inversion can not open.");
		exit(0);
	} 
	//extract file
	char line[1024];
	long int a[3];
	long int simulate_count=0;
	long int delly_count=0;
//	long int delly_count=0;
	long int lumpy_count=0;
	
	sv *simulate_array=(sv*)malloc(simulate_count*sizeof(sv));
	while(fgets(line,1024,delly_data)!=NULL){
		//if()
		  delly_count++;
		
	}
	//printf("delly_count=%ld\n",delly_count);
	rewind(delly_data);
	sv *delly_array=(sv*)malloc(delly_count*sizeof(sv));
	while(fgets(line,1024,delly_data)!=NULL){
		//if()
		  delly_count++;
		
	}
	//printf("delly_count=%ld\n",delly_count);
	rewind(delly_data);
	/*
	sv *delly_array=(sv*)malloc(delly_count*sizeof(sv));
	while(fgets(line,1024,lumpy_data)!=NULL){
		//if()
		  lumpy_count++;
		
	}
	*/
	//printf("delly_count=%ld\n",delly_count);
	rewind(lumpy_data);
	sv *lumpy_array=(sv*)malloc(lumpy_count*sizeof(sv));
	long int s_i=0;
	long int p_i=0;
	long int d_i=0;
	long int l_i=0;
	
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
           delly_array[p_i].start=a[0];
           delly_array[p_i].end=a[1];
           delly_array[p_i].length=a[2];
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,delly_array[p_i].start,delly_array[p_i].end,delly_array[p_i].length);
           p_i++;
         
		}//while(!feof(delly_data))
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
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,delly_array[p_i].start,delly_array[p_i].end,delly_array[p_i].length);
           d_i++;
         
		}//while(!feof(delly_data))  
		
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
           //printf("p_i=%ld %ld\t%ld\t%ld\n",p_i,delly_array[p_i].start,delly_array[p_i].end,delly_array[p_i].length);
           l_i++;
         
		}//while(!feof(delly_data)) 
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
		for(long int j=0;j<delly_count;j++){
			for(long int z=0;z<delly_count;z++){
			
				//printf("%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			if(((delly_array[j].start>=(lumpy_array[i].start-25))&&(delly_array[j].start<=(lumpy_array[i].start+25))
			 &&(delly_array[j].start>=(delly_array[z].start-25))&&(delly_array[j].start<=(delly_array[z].start+25))
			 &&(delly_array[z].start>=(lumpy_array[i].start-25))&&(delly_array[z].start<=(lumpy_array[i].start+25))
			 &&((delly_array[j].length==lumpy_array[i].length)==delly_array[z].length))
			||((delly_array[j].end>=(lumpy_array[i].end-25))&&(delly_array[j].end<=(lumpy_array[i].end+25))
			&&(delly_array[z].end>=(lumpy_array[i].end-25))&&(delly_array[z].end<=(lumpy_array[i].end+25))
			&&(delly_array[j].end>=(delly_array[z].end-25))&&(delly_array[j].end<=(delly_array[z].end+25))
			&&((delly_array[j].length==lumpy_array[i].length==delly_array[z].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			 if((delly_array[j].length>=1)&&(delly_array[j].length<=499)) inversion_1++;
			  	if((delly_array[j].length>=500)&&(delly_array[j].length<=999)) inversion_500++;
			  	if((delly_array[j].length>=1000)&&(delly_array[j].length<=1999)) inversion_1000++;
			  	if((delly_array[j].length>=2000)&&(delly_array[j].length<=2999)) inversion_2000++;
			  	if((delly_array[j].length>=3000)&&(delly_array[j].length<=3999)) inversion_3000++;
			  	if((delly_array[j].length>=4000)&&(delly_array[j].length<=4999)) inversion_4000++;
			  	if((delly_array[j].length>=5000)&&(delly_array[j].length<=5999)) inversion_5000++;
			  	if(delly_array[j].length>=6000) inversion_6000++;
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
		//||((delly_array[j].length>=(simulate_array[i].length-25))&&(delly_array[j].length<=(simulate_array[i].length+25))) 
	
	for(long int i=0;i<lumpy_count;i++){
		for(long int j=0;j<delly_count;j++){
				//printf("%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			if(((delly_array[j].start>=(lumpy_array[i].start-35))&&(delly_array[j].start<=(lumpy_array[i].start+35))&&((delly_array[j].length==lumpy_array[i].length)))
			  ||((delly_array[j].end>=(lumpy_array[i].end-35))&&(delly_array[j].end<=(lumpy_array[i].end+35))&&((delly_array[j].length==lumpy_array[i].length)))){
			  	fprintf(total_file,"%ld\t%ld\t%ld\n",delly_array[j].start,delly_array[j].end,delly_array[j].length);
			 if((delly_array[j].length>=1)&&(delly_array[j].length<=499)) inversion_1++;
			  	if((delly_array[j].length>=500)&&(delly_array[j].length<=999)) inversion_500++;
			  	if((delly_array[j].length>=1000)&&(delly_array[j].length<=1999)) inversion_1000++;
			  	if((delly_array[j].length>=2000)&&(delly_array[j].length<=2999)) inversion_2000++;
			  	if((delly_array[j].length>=3000)&&(delly_array[j].length<=3999)) inversion_3000++;
			  	if((delly_array[j].length>=4000)&&(delly_array[j].length<=4999)) inversion_4000++;
			  	if((delly_array[j].length>=5000)&&(delly_array[j].length<=5999)) inversion_5000++;
			  	if(delly_array[j].length>=6000) inversion_6000++;
			  }
		}
	}
	fprintf(total_file,"length(1-499bp):%ld\nlength(500-999bp):%ld\nlength(1000-1999bp):%ld\nlength(2000-2999bp):%ld\nlenght(3000-3999bp):%ld\nlenght(4000-4999bp):%ld\nlenght(5000-5999bp):%ld\nlenght(greater than or equal):%ld\n",
						   inversion_1,inversion_500,inversion_1000,inversion_2000,inversion_3000,inversion_4000,inversion_5000,inversion_6000);
	
						   
	    
	
	fclose(delly_data);
	fclose(lumpy_data);
	
	fclose(total_file);
	puts("finish.");
	return 0;
 } 
