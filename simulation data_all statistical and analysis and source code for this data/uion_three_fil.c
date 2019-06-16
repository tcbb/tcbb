#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	puts("start");
	puts("...");
	FILE *insertion,*inversion,*deletion,*union_file;
	if((insertion=fopen("F://data//insertion.txt","r"))==NULL){
		puts("insertion.txt can not open");
		exit(0);
	}
	if((deletion=fopen("F://data//deletion.txt","r"))==NULL){
		puts("deletion.txt can not open");
		exit(0);
	}
	if((inversion=fopen("F://data//insertion.txt","r"))==NULL){
		puts("inversion.txt can not open");
		exit(0);
	}
	if((union_file=fopen("F://data//union_three_file.txt","w+"))==NULL){
		puts("union_three_file.txt can not open");
		exit(0);
	}
	char line[1024];
	while(!feof(insertion)){
		if((fgets(line,1024,insertion))!=NULL) 
		  fprintf(union_file,"%s\n",line);
	}
	while(!feof(deletion)){
		if((fgets(line,1024,deletion))!=NULL)
		 fprintf(union_file,"%s\n",line);
	}
	while(!feof(inversion)){
		if((fgets(line,1024,inversion))!=NULL)
		 fprintf(union_file,"%s\n",line);
	}
	fclose(insertion);
	fclose(deletion);
	fclose(inversion);
	fclose(union_file); 
	puts("finish.");
	return 0;
}
