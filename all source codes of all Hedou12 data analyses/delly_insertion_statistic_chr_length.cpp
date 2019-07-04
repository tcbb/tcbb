#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

/****************************************************************************** 
function:total insertion length in every chr or everyscaffold
running environment:ubuntu 14.0.2 server operating system or windows8 desktop operating system
C compiler: GCC 4.7.4 or DEV-C++4.9.9.0
*************************************************************************/ 

string read_file_name="/home/2015525/delly/delly_insertion/delly_insertion_start_end_sequence.txt";//in ubuntu:input file path;if need, change your own file path
//in windows:string read_file_name="C:\\2015525\\delly\\delly_insertion\\delly_insertion_start_end_sequence.txt";
string write_file_name="/home/2015525/delly/delly_insertion/delly_insertion_statistic_chr_length.txt";//in ubuntu:output file path; if need,change your own file path
//in windows:string write_file_name="C:\\2015525\\delly\\delly_insertion\\delly_insertion_statistic_chr_length.txt";
string prefix_name="\\/home\\/2015525\\/delly\\/delly_insertion\\/";//output "/" need to use escape character "\"
//in windows:string prefix_name="C:\\\\2015525\\\\delly\\\\delly_insertion\\\\";
string chr_name[]={"Chr01","Chr02","Chr03","Chr04","Chr05","Chr06","Chr07","Chr08","Chr09","Chr10",
                   "Chr11","Chr12","Chr13","Chr14","Chr15","Chr16","Chr17","Chr18","Chr19","Chr20","Scaffold_"};



struct chr_length
{
	string chr;
	long long int length;
};


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
	vector <struct chr_length> s_chr_length;
	struct chr_length t_chr_length;
	
	write_file<<"Chr"<<"\t\t\t"<<"Length"<<endl;
	char split_array[1000],split_chr[50],split_start[30],split_end[50],string_length[50];//split array
	char* split_string;
	cout<<"The program starts ....."<<endl; 
	getline(read_file,line);
	while(getline(read_file,line)) //read w line in text file
	{
		char *string_to_char= new char[2000];//for insertion, this space is not enough
		strcpy(string_to_char,line.c_str());
		split_string=strtok(string_to_char,"\t .;");
		int i=0;
		string s;
		long long int sv_length;
		while(NULL!=split_string)// a line operation for a text
		{
			if(i==0)
			{
				strcpy(split_chr,split_string);
				s.assign(split_chr);
				//s_chr_length.push_back(s);
			    // s(&split_chr[0],&split_chr[strlen(split_chr)]);
			
			}
			if(i==3)
			{
				strcpy(string_length,split_string);
			//	cout<<"i="<<i<<" split_star="<<split_start<<endl;
			    sv_length=atoi(string_length);
			 } 
			
			
			split_string=strtok(NULL,"\t .;");
			i++;
		}// a line operation for a text
		t_chr_length.chr=s;
		t_chr_length.length=sv_length;
		s_chr_length.push_back(t_chr_length);
		delete string_to_char;
		
		//string(split_end);
	   
	//	cout<<"length="<<split_length<<endl;
		//write_file<<split_chr<<setw(10)<<setiosflags(ios::right)<<split_start<<setw(10)<<setiosflags(ios::left)<<split_end<<setw(10)<<setiosflags(ios::left)<<split_length<<endl;
		//getchar(); 
	
	}// read a line in a text file

    vector <long long int > chr1,chr2,chr3,chr4,chr5,chr6,chr7,chr8,chr9,chr10,chr11,chr12,chr13,chr14,chr15,chr16,chr17,chr18,chr19,chr20,chr21;
    long int scaffold_i=0;
    struct chr_length scaffold[3000];
  for(long long it=0;it<s_chr_length.size();it++)
  {
  	if((s_chr_length[it].chr).compare("Chr01")==0)
  	{
  		  chr1.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr02")==0)
  	{
  		  chr2.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr03")==0)
  	{
  		  chr3.push_back(s_chr_length[it].length);
	}
  	 if((s_chr_length[it].chr).compare("Chr04")==0)
  	{
  		  chr4.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr05")==0)
  	{
  		  chr5.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr06")==0)
  	{
  		  chr6.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr07")==0)
  	{
  		  chr7.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr08")==0)
  	{
  		  chr8.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr09")==0)
  	{
  		  chr9.push_back(s_chr_length[it].length);
	}
	if((s_chr_length[it].chr).compare("Chr10")==0)
  	{
  		  chr10.push_back(s_chr_length[it].length);
	}
	
	if((s_chr_length[it].chr).compare("Chr11")==0)
  	{
  		  chr11.push_back(s_chr_length[it].length);
	}
	
	if((s_chr_length[it].chr).compare("Chr12")==0)
  	{
  		  chr12.push_back(s_chr_length[it].length);
	}
	
	if((s_chr_length[it].chr).compare("Chr13")==0)
  	{
  		  chr13.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr14")==0)
  	{
  		  chr14.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr15")==0)
  	{
  		  chr15.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr16")==0)
  	{
  		  chr16.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr17")==0)
  	{
  		  chr17.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr18")==0)
  	{
  		  chr18.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr19")==0)
  	{
  		  chr19.push_back(s_chr_length[it].length);
	}
	
	
	if((s_chr_length[it].chr).compare("Chr20")==0)
  	{
  		  chr20.push_back(s_chr_length[it].length);
	}
	
	vector <string> chr21name;
	 

	
	if((s_chr_length[it].chr).substr(0,9).compare("scaffold_")==0)
  	{
  		scaffold[scaffold_i].length=s_chr_length[it].length;
  		scaffold[scaffold_i].chr=s_chr_length[it].chr;
  		scaffold_i++;
  		/*
  		  chr21.push_back(s_chr_length[it].length);
  		  chr21name.push_back(s_chr_length[it].chr);
  		  */ 
  		 // cout<<s_chr_length[it].chr<<endl;
	}
  	//cout<<s_chr_length[it].chr<<s_chr_length[it].length<<endl;
  	//getchar();
  }
 // bubble_sort(scaffold[scaffold_i].length,scaffold_i);
  
  
  sort(chr1.begin(),chr1.end());
  for(long int it_chr=0;it_chr<chr1.size();it_chr++)
  {
  	write_file<<"Chr01"<<"\t\t\t"<<chr1[it_chr]<<endl;
  }
  write_file<<"the total of Chr01 is "<<chr1.size()<<endl<<endl<<endl;
	
	
  sort(chr2.begin(),chr2.end());
  for(long int it_chr=0;it_chr<chr2.size();it_chr++)
  {
  	write_file<<"Chr02"<<"\t\t\t"<<chr2[it_chr]<<endl;
  }
  write_file<<"the total of Chr02 is "<<chr2.size()<<endl<<endl<<endl;
	
  sort(chr3.begin(),chr3.end());
  for(long int it_chr=0;it_chr<chr3.size();it_chr++)
  {
  	write_file<<"Chr03"<<"\t\t\t"<<chr3[it_chr]<<endl;
  }
  write_file<<"the total of Chr03 is "<<chr3.size()<<endl<<endl<<endl;
  
  
  sort(chr4.begin(),chr4.end());
  for(long int it_chr=0;it_chr<chr4.size();it_chr++)
  {
  	write_file<<"Chr04"<<"\t\t\t"<<chr4[it_chr]<<endl;
  }
  write_file<<"the total of Chr04 is "<<chr4.size()<<endl<<endl<<endl;


  sort(chr5.begin(),chr5.end());
  for(long int it_chr=0;it_chr<chr5.size();it_chr++)
  {
  	write_file<<"Chr05"<<"\t\t\t"<<chr5[it_chr]<<endl;
  }
  write_file<<"the total of Chr05 is "<<chr5.size()<<endl<<endl<<endl;
   
   
   sort(chr6.begin(),chr6.end());
  for(long int it_chr=0;it_chr<chr6.size();it_chr++)
  {
  	write_file<<"Chr06"<<"\t\t\t"<<chr6[it_chr]<<endl;
  }
  write_file<<"the total of Chr06 is "<<chr6.size()<<endl<<endl<<endl;

  sort(chr7.begin(),chr7.end());
  for(long int it_chr=0;it_chr<chr7.size();it_chr++)
  {
  	write_file<<"Chr07"<<"\t\t\t"<<chr7[it_chr]<<endl;
  }
  write_file<<"the total of Chr07 is "<<chr7.size()<<endl<<endl<<endl;
  
  
  sort(chr8.begin(),chr8.end());
  for(long int it_chr=0;it_chr<chr8.size();it_chr++)
  {
  	write_file<<"Chr08"<<"\t\t\t"<<chr8[it_chr]<<endl;
  }
  write_file<<"the total of Chr08 is "<<chr8.size()<<endl<<endl<<endl;
  
  sort(chr9.begin(),chr9.end());
  for(long int it_chr=0;it_chr<chr9.size();it_chr++)
  {
  	write_file<<"Chr09"<<"\t\t\t"<<chr9[it_chr]<<endl;
  }
  write_file<<"the total of Chr09 is "<<chr9.size()<<endl<<endl<<endl;
  
  
  sort(chr10.begin(),chr10.end());
  for(long int it_chr=0;it_chr<chr10.size();it_chr++)
  {
  	write_file<<"Chr10"<<"\t\t\t"<<chr10[it_chr]<<endl;
  }
  write_file<<"the total of Chr10 is "<<chr10.size()<<endl<<endl<<endl;

  sort(chr11.begin(),chr11.end());
  for(long int it_chr=0;it_chr<chr11.size();it_chr++)
  {
  	write_file<<"Chr11"<<"\t\t\t"<<chr11[it_chr]<<endl;
  }
  write_file<<"the total of Chr11 is "<<chr11.size()<<endl<<endl<<endl;

  sort(chr12.begin(),chr12.end());
  for(long int it_chr=0;it_chr<chr12.size();it_chr++)
  {
  	write_file<<"Chr12"<<"\t\t\t"<<chr12[it_chr]<<endl;
  }
  write_file<<"the total of Chr12 is "<<chr12.size()<<endl<<endl<<endl;

 sort(chr13.begin(),chr13.end());
  for(long int it_chr=0;it_chr<chr13.size();it_chr++)
  {
  	write_file<<"Chr13"<<"\t\t\t"<<chr13[it_chr]<<endl;
  }
  write_file<<"the total of Chr13 is "<<chr13.size()<<endl<<endl<<endl;
  
  sort(chr14.begin(),chr14.end());
  for(long int it_chr=0;it_chr<chr14.size();it_chr++)
  {
  	write_file<<"Chr14"<<"\t\t\t"<<chr14[it_chr]<<endl;
  }
  write_file<<"the total of Chr14 is "<<chr14.size()<<endl<<endl<<endl;
  
  
  sort(chr15.begin(),chr15.end());
  for(long int it_chr=0;it_chr<chr15.size();it_chr++)
  {
  	write_file<<"Chr15"<<"\t\t\t"<<chr15[it_chr]<<endl;
  }
  write_file<<"the total of Chr15 is "<<chr15.size()<<endl<<endl<<endl;
  
  
  sort(chr16.begin(),chr16.end());
  for(long int it_chr=0;it_chr<chr16.size();it_chr++)
  {
  	write_file<<"Chr16"<<"\t\t\t"<<chr16[it_chr]<<endl;
  }
  write_file<<"the total of Chr16 is "<<chr16.size()<<endl<<endl<<endl;
  
  sort(chr17.begin(),chr17.end());
  for(long int it_chr=0;it_chr<chr17.size();it_chr++)
  {
  	write_file<<"Chr17"<<"\t\t\t"<<chr17[it_chr]<<endl;
  }
  write_file<<"the total of Chr17 is "<<chr17.size()<<endl<<endl<<endl;

  sort(chr18.begin(),chr18.end());
  for(long int it_chr=0;it_chr<chr18.size();it_chr++)
  {
  	write_file<<"Chr18"<<"\t\t\t"<<chr18[it_chr]<<endl;
  }
  write_file<<"the total of Chr18 is "<<chr18.size()<<endl<<endl<<endl;

  sort(chr19.begin(),chr19.end());
  for(long int it_chr=0;it_chr<chr19.size();it_chr++)
  {
  	write_file<<"Chr19"<<"\t\t\t"<<chr19[it_chr]<<endl;
  }
  write_file<<"the total of Chr19 is "<<chr19.size()<<endl<<endl<<endl;
  
  sort(chr20.begin(),chr20.end());
  for(long int it_chr=0;it_chr<chr20.size();it_chr++)
  {
  	write_file<<"Chr20"<<"\t\t\t"<<chr20[it_chr]<<endl;
  }
  write_file<<"the total of Chr20 is "<<chr20.size()<<endl<<endl<<endl;
  
  
  
  	struct chr_length temp;  //sort
	for(long int i=0;i<scaffold_i;i++)
	{
		for(long int j=scaffold_i-1;j>=i;j--)
		{
			if(scaffold[j].length<scaffold[j-1].length)
			{
				temp=scaffold[j-1];
				//temp.length=scaffold[j-1].length;
				//temp.chr=scaffold[j-1].chr;
				scaffold[j-1]=scaffold[j];
				scaffold[j]=temp;
			}
		 } 
	}
  for(long int j=0;j<scaffold_i;j++)
  {
  	write_file<<scaffold[j].chr<<"\t\t\t"<<setiosflags(ios::left)<<scaffold[j].length<<setiosflags(ios::left)<<endl;
  }
   write_file<<"the total of SCaffold is "<<scaffold_i<<endl<<endl<<endl;
  
  /*sort(chr21.begin(),chr21.end());
  for(long int it_chr=0;it_chr<chr21.size();it_chr++)
  {
  	write_file<<"Chr21"<<"\t\t\t"<<chr21[it_chr]<<endl;
  }
  write_file<<"the total of Chr21 is "<<chr21.size()<<endl<<endl<<endl;
  */

  for(int i=0;i<21;i++)
  {
  	prefix_name+=chr_name[i];
  	//cout<<"prefix_name"<<prefix_name<<endl;
  	prefix_name+=".txt";
  	string temp_file_name;
  	temp_file_name=prefix_name;
  	
  	ofstream write_chr_file;
  	write_chr_file.open(temp_file_name.c_str());
  	if(i==0)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr1.size();it_chr++)
            {
  	         write_chr_file<<chr1[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i<<" is "<<chr1.size()<<endl<<endl<<endl;
	}
	
	if(i==1)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr2.size();it_chr++)
            {
  	         write_chr_file<<chr2[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr2.size()<<endl<<endl<<endl;
	}
    
    if(i==2)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr3.size();it_chr++)
            {
  	         write_chr_file<<chr3[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr3.size()<<endl<<endl<<endl;
	}

    if(i==3)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr4.size();it_chr++)
            {
  	         write_chr_file<<chr4[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr4.size()<<endl<<endl<<endl;
	}    
	
	
	if(i==4)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr5.size();it_chr++)
            {
  	         write_chr_file<<chr5[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr5.size()<<endl<<endl<<endl;
	}
	
	
	if(i==5)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr6.size();it_chr++)
            {
  	         write_chr_file<<chr6[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr6.size()<<endl<<endl<<endl;
	}
    
    
    if(i==6)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr7.size();it_chr++)
            {
  	         write_chr_file<<chr7[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr7.size()<<endl<<endl<<endl;
	}
    
    if(i==7)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr8.size();it_chr++)
            {
  	         write_chr_file<<chr8[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr8.size()<<endl<<endl<<endl;
	}
	
	if(i==8)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr9.size();it_chr++)
            {
  	         write_chr_file<<chr9[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr9.size()<<endl<<endl<<endl;
	}
	
	if(i==9)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr10.size();it_chr++)
            {
  	         write_chr_file<<chr10[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr10.size()<<endl<<endl<<endl;
	}
	
	
	if(i==10)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr11.size();it_chr++)
            {
  	         write_chr_file<<chr11[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr11.size()<<endl<<endl<<endl;
	}
	
	if(i==11)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr12.size();it_chr++)
            {
  	         write_chr_file<<chr12[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr12.size()<<endl<<endl<<endl;
	}
	
	
	if(i==12)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr13.size();it_chr++)
            {
  	         write_chr_file<<chr13[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr13.size()<<endl<<endl<<endl;
	}
	
	if(i==13)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr14.size();it_chr++)
            {
  	         write_chr_file<<chr14[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr14.size()<<endl<<endl<<endl;
	}
	
	if(i==14)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr15.size();it_chr++)
            {
  	         write_chr_file<<chr15[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr15.size()<<endl<<endl<<endl;
	}
	
    
    
    if(i==15)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr16.size();it_chr++)
            {
  	         write_chr_file<<chr16[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr16.size()<<endl<<endl<<endl;
	}
	
	
	if(i==16)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr17.size();it_chr++)
            {
  	         write_chr_file<<chr17[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr17.size()<<endl<<endl<<endl;
	}
	
	
	if(i==17)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr18.size();it_chr++)
            {
  	         write_chr_file<<chr18[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr18.size()<<endl<<endl<<endl;
	}
	
    
    
    if(i==18)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr19.size();it_chr++)
            {
  	         write_chr_file<<chr19[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr19.size()<<endl<<endl<<endl;
	}
	
	
	if(i==19)
  	{
  		 write_chr_file<<"Chr0"<<i+1<<endl;
  		 for(long int it_chr=0;it_chr<chr20.size();it_chr++)
            {
  	         write_chr_file<<chr20[it_chr]<<endl;
            }
      write_chr_file<<"the total of Chr0"<<i+1<<" is "<<chr20.size()<<endl<<endl<<endl;
	}
	
    
    if(i==20)
    {
    	write_chr_file<<"scaffold"<<endl;
    	for(long int j=0;j<scaffold_i;j++)
        {
  	      write_chr_file<<scaffold[j].length<<endl;
        }
         write_chr_file<<"the total of SCaffold is "<<scaffold_i<<endl<<endl<<endl;
	}
  
    write_chr_file.close();
  	prefix_name.erase(prefix_name.length()-9,prefix_name.length());
  	temp_file_name.erase(temp_file_name.length()-9,temp_file_name.length());
  	
  }

  
	
	
	read_file.close();
	write_file.close();
	cout<<endl<<"File finish!!"<<endl;
	return 1;
	
}


/*
if(s_chr_length[0].chr.substr(0,4).compare("Chr01")==0)
		{
			s_chr_length.length.push_back(sv_length);
		}
		if(s_chr_length.chr.substr(0,3).compare("Chr02")==0)
		  s_chr_length.length.push_back(sv_length);
		  
		  
		if(s_chr_length.chr.substr(0,3).compare("Chr03")==0)
	      s_chr_length.length.push_back(sv_length);		 
	      
	      
		if(s_chr_length.chr.substr(0,3).compare("Chr04")==0)
		  s_chr_length.length.push_back(sv_length);
		  
		  
		if(s_chr_length.chr.substr(0,3).compare("Chr05")==0)
          s_chr_length.length.push_back(sv_length);		
          
          
		if(s_chr_length.chr.substr(0,3).compare("Chr06")==0)
		  s_chr_length.length.push_back(sv_length);
		
		if(char_string_chr.substr(0,3).compare("Chr07")==0)
		  s_chr_length.length.push_back(sv_length);
		
     	if(s_chr_length.chr.substr(0,3).compare("Chr08")==0)
		  s_chr_length.length.push_back(sv_length);
		  
		if(s_chr_length.chr.substr(0,3).compare("Chr09")==0)
		  s_chr_length.length.push_back(sv_length);
		
		if(s_chr_length.chr.substr(0,3).compare("Chr10")==0)
		  s_chr_length.length.push_back(sv_length);
		  
		if(s_chr_length.chr.substr(0,3).compare("Chr11")==0)
		   s_chr_length.length.push_back(sv_length);
		   
		if(s_chr_length.chr.substr(0,3).compare("Chr12")==0)
		   s_chr_length.length.push_back(sv_length);
		
		if(s_chr_length.chr.substr(0,3).compare("Chr13")==0)
		   s_chr_length.length.push_back(sv_length);
		   
		if(s_chr_length.chr.substr(0,3).compare("Chr14")==0)
			s_chr_length.chr.length.push_back(sv_length);
	
		 if(s_chr_length.chr.substr(0,3).compare("Chr15")==0)
			s_chr_length.length.push_back(sv_length);
		
		 if(s_chr_length.chr.substr(0,3).compare("Chr16")==0)
			s_chr_length.length.push_back(sv_length);
			
		 if(s_chr_length.chr.substr(0,3).compare("Chr17")==0)
			s_chr_length.length.push_back(sv_length);
		
		 if(s_chr_length.chr.substr(0,3).compare("Chr18")==0)
			s_chr_length.length.push_back(sv_length);
		 
		 if(s_chr_length.chr.substr(0,3).compare("Chr19")==0)
		    s_chr_length.length.push_back(sv_length);
			
	     if(s_chr_length.chr.substr(0,3).compare("Chr20")==0)
			s_chr_length.length.push_back(sv_length);
				 
		if(s_chr_length.chr.substr(0,9).compare("scaffold_")==0)
			s_chr_length.length.push_back(sv_length);		//string(split_start);
*/









	/*
				if(char_string_chr.substr(0,3).compare("Chr01")==0)
				 chr[0]++;
				 if(char_string_chr.substr(0,3).compare("Chr02")==0)
				 chr[1]++;
				 if(char_string_chr.substr(0,3).compare("Chr03")==0)
				 chr[2]++;
				 if(char_string_chr.substr(0,3).compare("Chr04")==0)
				 chr[3]++;
				 if(char_string_chr.substr(0,3).compare("Chr05")==0)
				 chr[4]++;
				 if(char_string_chr.substr(0,3).compare("Chr06")==0)
				 chr[5]++;
				 if(char_string_chr.substr(0,3).compare("Chr07")==0)
				 chr[6]++;
				 if(char_string_chr.substr(0,3).compare("Chr08")==0)
				 chr[7]++;
				 if(char_string_chr.substr(0,3).compare("Chr09")==0)
				 chr[8]++;
				 if(char_string_chr.substr(0,3).compare("Chr10")==0)
				 chr[9]++;
				 if(char_string_chr.substr(0,3).compare("Chr11")==0)
				 chr[10]++;
				 if(char_string_chr.substr(0,3).compare("Chr12")==0)
				 chr[11]++;
				 if(char_string_chr.substr(0,3).compare("Chr13")==0)
				 chr[12]++;
				 if(char_string_chr.substr(0,3).compare("Chr14")==0)
				 chr[13]++;
				 if(char_string_chr.substr(0,3).compare("Chr15")==0)
				 chr[14]++;
				 if(char_string_chr.substr(0,3).compare("Chr16")==0)
				 chr[15]++;
				 if(char_string_chr.substr(0,3).compare("Chr17")==0)
				 chr[16]++;
				 if(char_string_chr.substr(0,3).compare("Chr18")==0)
				 chr[17]++;
				 if(char_string_chr.substr(0,3).compare("Chr19")==0)
				 chr[18]++;
				 if(char_string_chr.substr(0,3).compare("Chr20")==0)
				 chr[19]++;
				 if(char_string_chr.substr(0,9).compare("scaffold_")==0)
				scaffold++;
				//cout<<"i="<<i<<" split_chr="<<split_chr<<"aaaa";
				*/
