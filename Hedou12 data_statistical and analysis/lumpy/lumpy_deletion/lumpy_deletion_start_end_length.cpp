#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

/****************************************************************************** 
function:statistic start coordinates and end coordinates and deletion length from lumpy_deletion
running environment:ubuntu 14.0.2 server operating system or windows8 desktop operation system
C compiler: GCC 4.7.4 or DEV-C++4.9.9.0
*************************************************************************/ 


string read_file_name="/home/2015525/lumpy/lumpy_deletion/lumpy_deletion.vcf";//in ubuntu:input file path;if need,change your own file path
//in windwos:string read_file_name="C:\\2015525\\lumpy\\lumpy_deletion\\lumpy_deletion.txt";


string write_file_name="/home/2015525/lumpy/lumpy_deletion/lumpy_deletion_start_end_length.txt";//in ubuntu:output file path;if need,change your own file path
//in windwos:string write_file_name="C:\\2015525\\lumpy\\lumpy_deletion\\lumpy_deletion_start_end_length.txt";




int main(void)
{
	ifstream read_file;
	read_file.open(read_file_name.c_str());
	ofstream write_file;
	write_file.open(write_file_name.c_str());
	if(!read_file)	
	{
		cout<<"This file can not open"<<endl;
		exit(1);
	}
	string line;
	write_file<<"Chr"<<setw(10)<<"Start"<<setw(10)<<"End"<<setw(10)<<"Length"<<endl;
	char split_array[1000],split_chr[50],split_start[30],split_end[50];//split array
	char* split_string;
	cout<<"The program starts ....."<<endl; 
	while(getline(read_file,line))
	{
		char *string_to_char= new char[2000];//for insertion, this space is not enough
		strcpy(string_to_char,line.c_str());
		split_string=strtok(string_to_char,"\t .;");
		long int i=0;
		while(NULL!=split_string)
		{
			if(i==0)
			{
				strcpy(split_chr,split_string);
				//cout<<"i="<<i<<" split_chr="<<split_chr<<"aaaa";
			}
			if(i==1)
			{
				strcpy(split_start,split_string);
			//	cout<<"i="<<i<<" split_star="<<split_start<<endl;
			 } 
			//cout<<split_string<<" "<<endl;
			string char_string;
			char_string.assign(split_string);
			//string(char_string);
		   // string(char_string);
		    //char_string=split_string;
			if(char_string.substr(0,4).compare("END=")==0)
			{
				char_string.erase(0,4);
				strcpy(split_end,char_string.c_str());
				//cout<<"split_end="<<split_end<<endl;
//				cout<<"END="<<char_string<<endl;
			}
			
			split_string=strtok(NULL,"\t .;");
			i++;
		}
		delete string_to_char;
		//string(split_start);
		//string(split_end);
	   long long int split_length=abs(atol(split_start)-atol(split_end));
	//	cout<<"length="<<split_length<<endl;
		write_file<<split_chr<<setw(10)<<setiosflags(ios::right)<<split_start<<setw(10)<<setiosflags(ios::left)<<split_end<<setw(10)<<setiosflags(ios::left)<<split_length<<endl;
		//getchar(); 
	
	}
	read_file.close();
	write_file.close();
	cout<<endl<<"File finish!!"<<endl;
	return 1;
	
}
