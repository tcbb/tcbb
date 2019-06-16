#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;


/****************************************************************************** 
function:total the range of different insertion lengths in every chr or everyscaffold
running environment:ubuntu 14.0.2 server operating system or windows8 desktop operating system
C compiler: GCC 4.7.4 or DEV-C++4.9.9.0
*************************************************************************/ 

string read_file_name="/home/2015525/delly/delly_insertion/delly_insertion_statistic_chr_length.txt";//in ubuntu:input file path;if need,change your own file path
//in windows:string read_file_name="C:\\2015525\\delly\\delly_insertion\\delly_insertion_statistic_chr_length.txt";
string write_file_name="/home/2015525/delly/delly_insertion/delly_insertion_statistic_range.txt";//in ubuntu:output file path;if need,change your own file path
//in windows:string write_file_name="C:\\2015525\\delly\\delly_insertion\\delly_insertion_statistic_range.txt";
string prefix_name="\\/home\\/2015525\\/delly\\/delly_insertion\\/";//output "/" need to use escape character "\\"
//in windwos:string prefix_name="C:\\\\2015525\\\\delly\\\\delly_insertion\\\\";
struct chr_length
{
	string chr;
	long long int length;
};
int main()
{
	ifstream read_file;
	vector<struct chr_length> length_rangle;
	struct chr_length temp;
	read_file.open(read_file_name.c_str());
	if(!read_file)
	{
		cout<<"This file can not open."<<endl;
		exit(1);
	}
	ofstream write_file;
	write_file.open(write_file_name.c_str());
	string line;
	char *sentence=new char[200];
	getline(read_file,line);
	int i=0;
	cout<<"The programm starts to run. ........"<<endl;
	while(getline(read_file,line))
	{
		strcpy(sentence,line.c_str());
		char *split_string=strtok(sentence," \t");
		while(NULL!=split_string)// operator for a line
		{
			string char_string;
			char_string.assign(split_string);
			if(i==0)
			{
				if(char_string.substr(0,3).compare("Chr")==0)
				  temp.chr=char_string;
			//	cout<<"temp.chr"<<temp.chr<<endl;
				if(char_string.substr(0,9).compare("scaffold_")==0)
		         temp.chr=char_string;
			    // cout<<temp.chr<<endl;
			}
			if(1==i)
			{
			//	if(char_string.substr(0,5).compare("Chr01")==0)
				   long long int length=atoll(split_string);
			    temp.length=length;
			     //cout<<"i==1"<<temp.length<<endl;
				
			}
			split_string=strtok(NULL," \t");
			i++;
		}
		length_rangle.push_back(temp);
	//	(length_rangle_chr1.chr).push_back(char_string);
			 //    cout<<"i=0"<<split_string<<endl;	
	  i=0;
	}
	vector <long long int > chr1,chr2,chr3,chr4,chr5,chr6,chr7,chr8,chr9,chr10,chr11,chr12,chr13,
	                        chr14,chr15,chr16,chr17,chr18,chr19,chr20,scaffold;
	for(long long int m=0;m<length_rangle.size();m++)
	{
		if((length_rangle[m].chr).compare("Chr01")==0)
		 chr1.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr02")==0)
		 chr2.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr03")==0)
		 chr3.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr04")==0)
		 chr4.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr05")==0)
		 chr5.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr06")==0)
		 chr6.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr07")==0)
		 chr7.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr08")==0)
		 chr8.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr09")==0)
		 chr9.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr10")==0)
		 chr10.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr11")==0)
		 chr11.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr12")==0)
		 chr12.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr13")==0)
		 chr13.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr14")==0)
		 chr14.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr15")==0)
		 chr15.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr16")==0)
		 chr16.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr17")==0)
		 chr17.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr18")==0)
		 chr18.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr19")==0)
		 chr19.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).compare("Chr20")==0)
		 chr20.push_back((length_rangle[m]).length);
		 if((length_rangle[m].chr).substr(0,9).compare("scaffold_")==0)
		 scaffold.push_back((length_rangle[m]).length);		 
	}
	long int count[22]={0}; 
	for(long long int h=0;h<length_rangle.size();h++)
	{
		if(0<length_rangle[h].length&&length_rangle[h].length<50)
		 count[0]++;
		if(50<=length_rangle[h].length&&length_rangle[h].length<100)
		 count[1]++;
		if(100<=length_rangle[h].length&&length_rangle[h].length<150) 
		  count[2]++;
		if(150<=length_rangle[h].length&&length_rangle[h].length<200) 
		  count[3]++;  
		if(200<=length_rangle[h].length&&length_rangle[h].length<250) 
		  count[4]++;
		if(250<=length_rangle[h].length&&length_rangle[h].length<300) 
		  count[5]++;
		if(300<=length_rangle[h].length&&length_rangle[h].length<350) 
		  count[6]++;
	    if(350<=length_rangle[h].length&&length_rangle[h].length<400) 
		  count[7]++;
		if(400<=length_rangle[h].length&&length_rangle[h].length<450) 
		  count[8]++;
		if(450<=length_rangle[h].length&&length_rangle[h].length<500) 
		  count[9]++;
		if(500<=length_rangle[h].length&&length_rangle[h].length<550) 
		  count[10]++;
		if(550<=length_rangle[h].length&&length_rangle[h].length<600) 
		  count[11]++;
		if(600<=length_rangle[h].length&&length_rangle[h].length<650)
		  count[12]++;
		if(650<=length_rangle[h].length&&length_rangle[h].length<700)
		  count[13]++;
		if(700<=length_rangle[h].length&&length_rangle[h].length<750)
		  count[14]++;
		if(750<=length_rangle[h].length&&length_rangle[h].length<800)
		  count[15]++;
		if(800<=length_rangle[h].length&&length_rangle[h].length<850)
		 count[16]++;
		if(850<=length_rangle[h].length&&length_rangle[h].length<900)
		 count[17]++;
		if(900<=length_rangle[h].length&&length_rangle[h].length<950)
		 count[18]++;
		if(950<=length_rangle[h].length&&length_rangle[h].length<1000)
		 count[19]++;
		if(1000<=length_rangle[h].length&&length_rangle[h].length<1500)
		count[20]++;
		if(1500<=length_rangle[h].length)
		 count[21]++;
		
	}
	for(int i=0;i<22;i++)
	{
		write_file<<count[i]<<endl;
	}
	write_file<<"\n\n"<<"the segment totaol:"<<endl;
	write_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
	write_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
    write_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
	write_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	write_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	write_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	write_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	write_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	write_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	write_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	write_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
		
	write_file.close();
	
		ofstream w_file;
	for(int kk=0;kk<22;kk++)
    count[kk]=0;
	for(int i=1;i<=21;i++) 
	{
		if(i==1)
		{
			prefix_name+="Chr01_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr1.size();j++)
			{
				if(0<chr1[j]&&chr1[j]<50)
	 	          count[0]++;
		        if(50<=chr1[j]&&chr1[j]<100)
		          count[1]++;
	        	if(100<=chr1[j]&&chr1[j]<150) 
		          count[2]++;
		        if(150<=chr1[j]&&chr1[j]<200) 
		          count[3]++;  
		        if(200<=chr1[j]&&chr1[j]<250) 
		          count[4]++;
	        	if(250<=chr1[j]&&chr1[j]<300) 
		          count[5]++;
		        if(300<=chr1[j]&&chr1[j]<350) 
		         count[6]++;
	            if(350<=chr1[j]&&chr1[j]<400) 
		         count[7]++;
	        	if(400<=chr1[j]&&chr1[j]<450) 
		         count[8]++;
		        if(450<=chr1[j]&&chr1[j]<500) 
		         count[9]++;
	        	if(500<=chr1[j]&&chr1[j]<550) 
		        count[10]++;
		        if(550<=chr1[j]&&chr1[j]<600) 
	  	         count[11]++;
	        	if(600<=chr1[j]&&chr1[j]<650)
		         count[12]++;
		        if(650<=chr1[j]&&chr1[j]<700)
		         count[13]++;
		        if(700<=chr1[j]&&chr1[j]<750)
		         count[14]++;
		       if(750<=chr1[j]&&chr1[j]<800)
		         count[15]++;
		        if(800<=chr1[j]&&chr1[j]<850)
		         count[16]++;
	        	if(850<=chr1[j]&&chr1[j]<900)
		         count[17]++;
		        if(900<=chr1[j]&&chr1[j]<950)
		         count[18]++;
		        if(950<=chr1[j]&&chr1[j]<1000)
		         count[19]++;
		        if(1000<=chr1[j]&&chr1[j]<1500)
		          count[20]++;
		        if(1500<=chr1[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
	    	prefix_name.clear();
		}
			if(i==2)
		{
			prefix_name+="Chr02_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr2.size();j++)
			{
				if(0<chr2[j]&&chr2[j]<50)
	 	          count[0]++;
		        if(50<=chr2[j]&&chr2[j]<100)
		          count[1]++;
	        	if(100<=chr2[j]&&chr2[j]<150) 
		          count[2]++;
		        if(150<=chr2[j]&&chr2[j]<200) 
		          count[3]++;  
		        if(200<=chr2[j]&&chr2[j]<250) 
		          count[4]++;
	        	if(250<=chr2[j]&&chr2[j]<300) 
		          count[5]++;
		        if(300<=chr2[j]&&chr2[j]<350) 
		         count[6]++;
	            if(350<=chr2[j]&&chr2[j]<400) 
		         count[7]++;
	        	if(400<=chr2[j]&&chr2[j]<450) 
		         count[8]++;
		        if(450<=chr2[j]&&chr2[j]<500) 
		         count[9]++;
	        	if(500<=chr2[j]&&chr2[j]<550) 
		        count[10]++;
		        if(550<=chr2[j]&&chr2[j]<600) 
	  	         count[11]++;
	        	if(600<=chr2[j]&&chr2[j]<650)
		         count[12]++;
		        if(650<=chr2[j]&&chr2[j]<700)
		         count[13]++;
		        if(700<=chr2[j]&&chr2[j]<750)
		         count[14]++;
		       if(750<=chr2[j]&&chr2[j]<800)
		         count[15]++;
		        if(800<=chr2[j]&&chr2[j]<850)
		         count[16]++;
	        	if(850<=chr2[j]&&chr2[j]<900)
		         count[17]++;
		        if(900<=chr2[j]&&chr2[j]<950)
		         count[18]++;
		        if(950<=chr2[j]&&chr2[j]<1000)
		         count[19]++;
		        if(1000<=chr2[j]&&chr2[j]<1500)
		          count[20]++;
		        if(1500<=chr2[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
	        	for(int k=0;k<22;k++)
			    count[k]=0;
	        w_file.close();
		   prefix_name.clear();
		}//if(i==2)
			if(i==3)
		{
			prefix_name+="Chr03_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr3.size();j++)
			{
				if(0<chr3[j]&&chr3[j]<50)
	 	          count[0]++;
		        if(50<=chr3[j]&&chr3[j]<100)
		          count[1]++;
	        	if(100<=chr3[j]&&chr3[j]<150) 
		          count[2]++;
		        if(150<=chr3[j]&&chr3[j]<200) 
		          count[3]++;  
		        if(200<=chr3[j]&&chr3[j]<250) 
		          count[4]++;
	        	if(250<=chr1[j]&&chr1[j]<300) 
		          count[5]++;
		        if(300<=chr3[j]&&chr3[j]<350) 
		         count[6]++;
	            if(350<=chr3[j]&&chr3[j]<400) 
		         count[7]++;
	        	if(400<=chr3[j]&&chr3[j]<450) 
		         count[8]++;
		        if(450<=chr3[j]&&chr3[j]<500) 
		         count[9]++;
	        	if(500<=chr3[j]&&chr3[j]<550) 
		        count[10]++;
		        if(550<=chr3[j]&&chr3[j]<600) 
	  	         count[11]++;
	        	if(600<=chr3[j]&&chr3[j]<650)
		         count[12]++;
		        if(650<=chr3[j]&&chr3[j]<700)
		         count[13]++;
		        if(700<=chr3[j]&&chr3[j]<750)
		         count[14]++;
		       if(750<=chr3[j]&&chr3[j]<800)
		         count[15]++;
		        if(800<=chr3[j]&&chr3[j]<850)
		         count[16]++;
	        	if(850<=chr3[j]&&chr3[j]<900)
		         count[17]++;
		        if(900<=chr3[j]&&chr3[j]<950)
		         count[18]++;
		        if(950<=chr3[j]&&chr3[j]<1000)
		         count[19]++;
		        if(1000<=chr3[j]&&chr3[j]<1500)
		          count[20]++;
		        if(1500<=chr3[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==3)
		
			if(i==4)
		{
			prefix_name+="Chr04_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr4.size();j++)
			{
			if(0<chr4[j]&&chr4[j]<50)
	 	          count[0]++;
		        if(50<=chr4[j]&&chr4[j]<100)
		          count[1]++;
	        	if(100<=chr4[j]&&chr4[j]<150) 
		          count[2]++;
		        if(150<=chr4[j]&&chr4[j]<200) 
		          count[3]++;  
		        if(200<=chr4[j]&&chr4[j]<250) 
		          count[4]++;
	        	if(250<=chr4[j]&&chr4[j]<300) 
		          count[5]++;
		        if(300<=chr4[j]&&chr4[j]<350) 
		         count[6]++;
	            if(350<=chr4[j]&&chr4[j]<400) 
		         count[7]++;
	        	if(400<=chr4[j]&&chr4[j]<450) 
		         count[8]++;
		        if(450<=chr4[j]&&chr4[j]<500) 
		         count[9]++;
	        	if(500<=chr4[j]&&chr4[j]<550) 
		        count[10]++;
		        if(550<=chr4[j]&&chr4[j]<600) 
	  	         count[11]++;
	        	if(600<=chr4[j]&&chr4[j]<650)
		         count[12]++;
		        if(650<=chr4[j]&&chr4[j]<700)
		         count[13]++;
		        if(700<=chr4[j]&&chr4[j]<750)
		         count[14]++;
		       if(750<=chr4[j]&&chr4[j]<800)
		         count[15]++;
		        if(800<=chr4[j]&&chr4[j]<850)
		         count[16]++;
	        	if(850<=chr4[j]&&chr4[j]<900)
		         count[17]++;
		        if(900<=chr4[j]&&chr4[j]<950)
		         count[18]++;
		        if(950<=chr4[j]&&chr4[j]<1000)
		         count[19]++;
		        if(1000<=chr4[j]&&chr4[j]<1500)
		          count[20]++;
		        if(1500<=chr4[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==4)
			if(i==5)
		{
			prefix_name+="Chr05_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr5.size();j++)
			{
			if(0<chr1[j]&&chr1[j]<50)
	 	          count[0]++;
		        if(50<=chr5[j]&&chr5[j]<100)
		          count[1]++;
	        	if(100<=chr1[j]&&chr5[j]<150) 
		          count[2]++;
		        if(150<=chr5[j]&&chr5[j]<200) 
		          count[3]++;  
		        if(200<=chr5[j]&&chr5[j]<250) 
		          count[4]++;
	        	if(250<=chr5[j]&&chr5[j]<300) 
		          count[5]++;
		        if(300<=chr5[j]&&chr5[j]<350) 
		         count[6]++;
	            if(350<=chr5[j]&&chr5[j]<400) 
		         count[7]++;
	        	if(400<=chr5[j]&&chr5[j]<450) 
		         count[8]++;
		        if(450<=chr5[j]&&chr5[j]<500) 
		         count[9]++;
	        	if(500<=chr5[j]&&chr5[j]<550) 
		        count[10]++;
		        if(550<=chr5[j]&&chr5[j]<600) 
	  	         count[11]++;
	        	if(600<=chr5[j]&&chr5[j]<650)
		         count[12]++;
		        if(650<=chr5[j]&&chr5[j]<700)
		         count[13]++;
		        if(700<=chr5[j]&&chr5[j]<750)
		         count[14]++;
		       if(750<=chr5[j]&&chr5[j]<800)
		         count[15]++;
		        if(800<=chr5[j]&&chr5[j]<850)
		         count[16]++;
	        	if(850<=chr5[j]&&chr5[j]<900)
		         count[17]++;
		        if(900<=chr5[j]&&chr5[j]<950)
		         count[18]++;
		        if(950<=chr5[j]&&chr5[j]<1000)
		         count[19]++;
		        if(1000<=chr5[j]&&chr5[j]<1500)
		          count[20]++;
		        if(1500<=chr5[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==5)
			if(i==6)
		{
			prefix_name+="Chr06_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr6.size();j++)
			{
				if(0<chr6[j]&&chr6[j]<50)
	 	          count[0]++;
		        if(50<=chr6[j]&&chr6[j]<100)
		          count[1]++;
	        	if(100<=chr6[j]&&chr6[j]<150) 
		          count[2]++;
		        if(150<=chr6[j]&&chr6[j]<200) 
		          count[3]++;  
		        if(200<=chr6[j]&&chr6[j]<250) 
		          count[4]++;
	        	if(250<=chr6[j]&&chr1[j]<300) 
		          count[5]++;
		        if(300<=chr6[j]&&chr6[j]<350) 
		         count[6]++;
	            if(350<=chr6[j]&&chr6[j]<400) 
		         count[7]++;
	        	if(400<=chr6[j]&&chr6[j]<450) 
		         count[8]++;
		        if(450<=chr6[j]&&chr6[j]<500) 
		         count[9]++;
	        	if(500<=chr6[j]&&chr6[j]<550) 
		        count[10]++;
		        if(550<=chr6[j]&&chr6[j]<600) 
	  	         count[11]++;
	        	if(600<=chr6[j]&&chr6[j]<650)
		         count[12]++;
		        if(650<=chr6[j]&&chr6[j]<700)
		         count[13]++;
		        if(700<=chr6[j]&&chr6[j]<750)
		         count[14]++;
		       if(750<=chr6[j]&&chr6[j]<800)
		         count[15]++;
		        if(800<=chr6[j]&&chr6[j]<850)
		         count[16]++;
	        	if(850<=chr6[j]&&chr6[j]<900)
		         count[17]++;
		        if(900<=chr6[j]&&chr6[j]<950)
		         count[18]++;
		        if(950<=chr6[j]&&chr6[j]<1000)
		         count[19]++;
		        if(1000<=chr6[j]&&chr6[j]<1500)
		          count[20]++;
		        if(1500<=chr6[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i=6)
			if(i==7)
		{
			prefix_name+="Chr07_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr7.size();j++)
			{
			if(0<chr7[j]&&chr7[j]<50)
	 	          count[0]++;
		        if(50<=chr7[j]&&chr7[j]<100)
		          count[1]++;
	        	if(100<=chr7[j]&&chr7[j]<150) 
		          count[2]++;
		        if(150<=chr7[j]&&chr7[j]<200) 
		          count[3]++;  
		        if(200<=chr7[j]&&chr7[j]<250) 
		          count[4]++;
	        	if(250<=chr7[j]&&chr7[j]<300) 
		          count[5]++;
		        if(300<=chr7[j]&&chr7[j]<350) 
		         count[6]++;
	            if(350<=chr7[j]&&chr7[j]<400) 
		         count[7]++;
	        	if(400<=chr7[j]&&chr7[j]<450) 
		         count[8]++;
		        if(450<=chr7[j]&&chr7[j]<500) 
		         count[9]++;
	        	if(500<=chr7[j]&&chr7[j]<550) 
		        count[10]++;
		        if(550<=chr7[j]&&chr7[j]<600) 
	  	         count[11]++;
	        	if(600<=chr7[j]&&chr7[j]<650)
		         count[12]++;
		        if(650<=chr7[j]&&chr7[j]<700)
		         count[13]++;
		        if(700<=chr7[j]&&chr7[j]<750)
		         count[14]++;
		       if(750<=chr7[j]&&chr7[j]<800)
		         count[15]++;
		        if(800<=chr7[j]&&chr7[j]<850)
		         count[16]++;
	        	if(850<=chr7[j]&&chr7[j]<900)
		         count[17]++;
		        if(900<=chr7[j]&&chr7[j]<950)
		         count[18]++;
		        if(950<=chr1[j]&&chr7[j]<1000)
		         count[19]++;
		        if(1000<=chr7[j]&&chr7[j]<1500)
		          count[20]++;
		        if(1500<=chr7[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==7)
			if(i==8)
		{
			prefix_name+="Chr08_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr8.size();j++)
			{
			if(0<chr8[j]&&chr8[j]<50)
	 	          count[0]++;
		        if(50<=chr8[j]&&chr8[j]<100)
		          count[1]++;
	        	if(100<=chr8[j]&&chr8[j]<150) 
		          count[2]++;
		        if(150<=chr8[j]&&chr8[j]<200) 
		          count[3]++;  
		        if(200<=chr8[j]&&chr8[j]<250) 
		          count[4]++;
	        	if(250<=chr8[j]&&chr8[j]<300) 
		          count[5]++;
		        if(300<=chr8[j]&&chr8[j]<350) 
		         count[6]++;
	            if(350<=chr8[j]&&chr8[j]<400) 
		         count[7]++;
	        	if(400<=chr8[j]&&chr8[j]<450) 
		         count[8]++;
		        if(450<=chr8[j]&&chr8[j]<500) 
		         count[9]++;
	        	if(500<=chr8[j]&&chr8[j]<550) 
		        count[10]++;
		        if(550<=chr8[j]&&chr8[j]<600) 
	  	         count[11]++;
	        	if(600<=chr8[j]&&chr8[j]<650)
		         count[12]++;
		        if(650<=chr8[j]&&chr8[j]<700)
		         count[13]++;
		        if(700<=chr8[j]&&chr8[j]<750)
		         count[14]++;
		       if(750<=chr8[j]&&chr8[j]<800)
		         count[15]++;
		        if(800<=chr8[j]&&chr8[j]<850)
		         count[16]++;
	        	if(850<=chr8[j]&&chr8[j]<900)
		         count[17]++;
		        if(900<=chr8[j]&&chr8[j]<950)
		         count[18]++;
		        if(950<=chr8[j]&&chr8[j]<1000)
		         count[19]++;
		        if(1000<=chr8[j]&&chr8[j]<1500)
		          count[20]++;
		        if(1500<=chr8[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==8)
			if(i==9)
		{
			prefix_name+="Chr09_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr9.size();j++)
			{
				if(0<chr9[j]&&chr9[j]<50)
	 	          count[0]++;
		        if(50<=chr9[j]&&chr9[j]<100)
		          count[1]++;
	        	if(100<=chr9[j]&&chr9[j]<150) 
		          count[2]++;
		        if(150<=chr9[j]&&chr9[j]<200) 
		          count[3]++;  
		        if(200<=chr9[j]&&chr9[j]<250) 
		          count[4]++;
	        	if(250<=chr9[j]&&chr9[j]<300) 
		          count[5]++;
		        if(300<=chr9[j]&&chr9[j]<350) 
		         count[6]++;
	            if(350<=chr9[j]&&chr9[j]<400) 
		         count[7]++;
	        	if(400<=chr9[j]&&chr9[j]<450) 
		         count[8]++;
		        if(450<=chr9[j]&&chr9[j]<500) 
		         count[9]++;
	        	if(500<=chr9[j]&&chr9[j]<550) 
		        count[10]++;
		        if(550<=chr9[j]&&chr9[j]<600) 
	  	         count[11]++;
	        	if(600<=chr9[j]&&chr9[j]<650)
		         count[12]++;
		        if(650<=chr9[j]&&chr9[j]<700)
		         count[13]++;
		        if(700<=chr9[j]&&chr9[j]<750)
		         count[14]++;
		       if(750<=chr9[j]&&chr9[j]<800)
		         count[15]++;
		        if(800<=chr9[j]&&chr9[j]<850)
		         count[16]++;
	        	if(850<=chr9[j]&&chr9[j]<900)
		         count[17]++;
		        if(900<=chr9[j]&&chr9[j]<950)
		         count[18]++;
		        if(950<=chr9[j]&&chr9[j]<1000)
		         count[19]++;
		        if(1000<=chr9[j]&&chr9[j]<1500)
		          count[20]++;
		        if(1500<=chr9[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==9)
			if(i==10)
		{
			prefix_name+="Chr10_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr10.size();j++)
			{
				if(0<chr10[j]&&chr10[j]<50)
	 	          count[0]++;
		        if(50<=chr10[j]&&chr10[j]<100)
		          count[1]++;
	        	if(100<=chr10[j]&&chr10[j]<150) 
		          count[2]++;
		        if(150<=chr10[j]&&chr10[j]<200) 
		          count[3]++;  
		        if(200<=chr10[j]&&chr10[j]<250) 
		          count[4]++;
	        	if(250<=chr10[j]&&chr10[j]<300) 
		          count[5]++;
		        if(300<=chr10[j]&&chr10[j]<350) 
		         count[6]++;
	            if(350<=chr10[j]&&chr10[j]<400) 
		         count[7]++;
	        	if(400<=chr10[j]&&chr10[j]<450) 
		         count[8]++;
		        if(450<=chr10[j]&&chr10[j]<500) 
		         count[9]++;
	        	if(500<=chr10[j]&&chr10[j]<550) 
		        count[10]++;
		        if(550<=chr10[j]&&chr10[j]<600) 
	  	         count[11]++;
	        	if(600<=chr10[j]&&chr10[j]<650)
		         count[12]++;
		        if(650<=chr10[j]&&chr10[j]<700)
		         count[13]++;
		        if(700<=chr10[j]&&chr10[j]<750)
		         count[14]++;
		       if(750<=chr10[j]&&chr10[j]<800)
		         count[15]++;
		        if(800<=chr10[j]&&chr10[j]<850)
		         count[16]++;
	        	if(850<=chr10[j]&&chr10[j]<900)
		         count[17]++;
		        if(900<=chr10[j]&&chr10[j]<950)
		         count[18]++;
		        if(950<=chr10[j]&&chr10[j]<1000)
		         count[19]++;
		        if(1000<=chr10[j]&&chr10[j]<1500)
		          count[20]++;
		        if(1500<=chr10[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==10)
			if(i==11)
		{
			prefix_name+="Chr11_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr11.size();j++)
			{
				if(0<chr11[j]&&chr11[j]<50)
	 	          count[0]++;
		        if(50<=chr11[j]&&chr11[j]<100)
		          count[1]++;
	        	if(100<=chr11[j]&&chr11[j]<150) 
		          count[2]++;
		        if(150<=chr11[j]&&chr11[j]<200) 
		          count[3]++;  
		        if(200<=chr11[j]&&chr11[j]<250) 
		          count[4]++;
	        	if(250<=chr11[j]&&chr11[j]<300) 
		          count[5]++;
		        if(300<=chr11[j]&&chr11[j]<350) 
		         count[6]++;
	            if(350<=chr11[j]&&chr11[j]<400) 
		         count[7]++;
	        	if(400<=chr11[j]&&chr11[j]<450) 
		         count[8]++;
		        if(450<=chr11[j]&&chr11[j]<500) 
		         count[9]++;
	        	if(500<=chr11[j]&&chr11[j]<550) 
		        count[10]++;
		        if(550<=chr11[j]&&chr11[j]<600) 
	  	         count[11]++;
	        	if(600<=chr11[j]&&chr11[j]<650)
		         count[12]++;
		        if(650<=chr11[j]&&chr11[j]<700)
		         count[13]++;
		        if(700<=chr11[j]&&chr11[j]<750)
		         count[14]++;
		       if(750<=chr11[j]&&chr11[j]<800)
		         count[15]++;
		        if(800<=chr11[j]&&chr11[j]<850)
		         count[16]++;
	        	if(850<=chr11[j]&&chr11[j]<900)
		         count[17]++;
		        if(900<=chr11[j]&&chr11[j]<950)
		         count[18]++;
		        if(950<=chr11[j]&&chr11[j]<1000)
		         count[19]++;
		        if(1000<=chr11[j]&&chr11[j]<1500)
		          count[20]++;
		        if(1500<=chr11[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==11)
		if(i==12)
		{
			prefix_name+="Chr12_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr12.size();j++)
			{
				if(0<chr12[j]&&chr12[j]<50)
	 	          count[0]++;
		        if(50<=chr12[j]&&chr12[j]<100)
		          count[1]++;
	        	if(100<=chr12[j]&&chr12[j]<150) 
		          count[2]++;
		        if(150<=chr12[j]&&chr12[j]<200) 
		          count[3]++;  
		        if(200<=chr12[j]&&chr12[j]<250) 
		          count[4]++;
	        	if(250<=chr12[j]&&chr12[j]<300) 
		          count[5]++;
		        if(300<=chr12[j]&&chr12[j]<350) 
		         count[6]++;
	            if(350<=chr12[j]&&chr12[j]<400) 
		         count[7]++;
	        	if(400<=chr12[j]&&chr12[j]<450) 
		         count[8]++;
		        if(450<=chr12[j]&&chr12[j]<500) 
		         count[9]++;
	        	if(500<=chr12[j]&&chr12[j]<550) 
		        count[10]++;
		        if(550<=chr12[j]&&chr12[j]<600) 
	  	         count[11]++;
	        	if(600<=chr12[j]&&chr12[j]<650)
		         count[12]++;
		        if(650<=chr12[j]&&chr12[j]<700)
		         count[13]++;
		        if(700<=chr12[j]&&chr12[j]<750)
		         count[14]++;
		       if(750<=chr12[j]&&chr12[j]<800)
		         count[15]++;
		        if(800<=chr12[j]&&chr12[j]<850)
		         count[16]++;
	        	if(850<=chr12[j]&&chr12[j]<900)
		         count[17]++;
		        if(900<=chr12[j]&&chr12[j]<950)
		         count[18]++;
		        if(950<=chr12[j]&&chr12[j]<1000)
		         count[19]++;
		        if(1000<=chr12[j]&&chr12[j]<1500)
		          count[20]++;
		        if(1500<=chr12[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==12)
		if(i==13)
		{
			prefix_name+="Chr13_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr13.size();j++)
			{
			if(0<chr13[j]&&chr13[j]<50)
	 	          count[0]++;
		        if(50<=chr13[j]&&chr13[j]<100)
		          count[1]++;
	        	if(100<=chr13[j]&&chr13[j]<150) 
		          count[2]++;
		        if(150<=chr13[j]&&chr13[j]<200) 
		          count[3]++;  
		        if(200<=chr13[j]&&chr13[j]<250) 
		          count[4]++;
	        	if(250<=chr13[j]&&chr13[j]<300) 
		          count[5]++;
		        if(300<=chr13[j]&&chr13[j]<350) 
		         count[6]++;
	            if(350<=chr13[j]&&chr13[j]<400) 
		         count[7]++;
	        	if(400<=chr13[j]&&chr13[j]<450) 
		         count[8]++;
		        if(450<=chr13[j]&&chr13[j]<500) 
		         count[9]++;
	        	if(500<=chr13[j]&&chr13[j]<550) 
		        count[10]++;
		        if(550<=chr13[j]&&chr13[j]<600) 
	  	         count[11]++;
	        	if(600<=chr13[j]&&chr13[j]<650)
		         count[12]++;
		        if(650<=chr13[j]&&chr13[j]<700)
		         count[13]++;
		        if(700<=chr13[j]&&chr13[j]<750)
		         count[14]++;
		       if(750<=chr13[j]&&chr13[j]<800)
		         count[15]++;
		        if(800<=chr13[j]&&chr13[j]<850)
		         count[16]++;
	        	if(850<=chr13[j]&&chr13[j]<900)
		         count[17]++;
		        if(900<=chr13[j]&&chr13[j]<950)
		         count[18]++;
		        if(950<=chr13[j]&&chr13[j]<1000)
		         count[19]++;
		        if(1000<=chr13[j]&&chr13[j]<1500)
		          count[20]++;
		        if(1500<=chr13[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==13)
		if(i==14)
		{
			prefix_name+="Chr14_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr14.size();j++)
			{
			if(0<chr14[j]&&chr14[j]<50)
	 	          count[0]++;
		        if(50<=chr14[j]&&chr14[j]<100)
		          count[1]++;
	        	if(100<=chr14[j]&&chr14[j]<150) 
		          count[2]++;
		        if(150<=chr14[j]&&chr14[j]<200) 
		          count[3]++;  
		        if(200<=chr14[j]&&chr14[j]<250) 
		          count[4]++;
	        	if(250<=chr14[j]&&chr14[j]<300) 
		          count[5]++;
		        if(300<=chr14[j]&&chr14[j]<350) 
		         count[6]++;
	            if(350<=chr14[j]&&chr14[j]<400) 
		         count[7]++;
	        	if(400<=chr14[j]&&chr14[j]<450) 
		         count[8]++;
		        if(450<=chr14[j]&&chr14[j]<500) 
		         count[9]++;
	        	if(500<=chr14[j]&&chr14[j]<550) 
		        count[10]++;
		        if(550<=chr14[j]&&chr14[j]<600) 
	  	         count[11]++;
	        	if(600<=chr14[j]&&chr14[j]<650)
		         count[12]++;
		        if(650<=chr14[j]&&chr14[j]<700)
		         count[13]++;
		        if(700<=chr14[j]&&chr14[j]<750)
		         count[14]++;
		       if(750<=chr14[j]&&chr14[j]<800)
		         count[15]++;
		        if(800<=chr14[j]&&chr14[j]<850)
		         count[16]++;
	        	if(850<=chr14[j]&&chr14[j]<900)
		         count[17]++;
		        if(900<=chr14[j]&&chr14[j]<950)
		         count[18]++;
		        if(950<=chr14[j]&&chr14[j]<1000)
		         count[19]++;
		        if(1000<=chr14[j]&&chr14[j]<1500)
		          count[20]++;
		        if(1500<=chr14[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==14)
		if(i==15)
		{
			prefix_name+="Chr15_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr15.size();j++)
			{
				if(0<chr15[j]&&chr15[j]<50)
	 	          count[0]++;
		        if(50<=chr15[j]&&chr15[j]<100)
		          count[1]++;
	        	if(100<=chr15[j]&&chr15[j]<150) 
		          count[2]++;
		        if(150<=chr15[j]&&chr15[j]<200) 
		          count[3]++;  
		        if(200<=chr15[j]&&chr15[j]<250) 
		          count[4]++;
	        	if(250<=chr15[j]&&chr15[j]<300) 
		          count[5]++;
		        if(300<=chr15[j]&&chr15[j]<350) 
		         count[6]++;
	            if(350<=chr15[j]&&chr15[j]<400) 
		         count[7]++;
	        	if(400<=chr15[j]&&chr15[j]<450) 
		         count[8]++;
		        if(450<=chr15[j]&&chr15[j]<500) 
		         count[9]++;
	        	if(500<=chr15[j]&&chr15[j]<550) 
		        count[10]++;
		        if(550<=chr15[j]&&chr15[j]<600) 
	  	         count[11]++;
	        	if(600<=chr15[j]&&chr15[j]<650)
		         count[12]++;
		        if(650<=chr15[j]&&chr15[j]<700)
		         count[13]++;
		        if(700<=chr15[j]&&chr15[j]<750)
		         count[14]++;
		       if(750<=chr15[j]&&chr15[j]<800)
		         count[15]++;
		        if(800<=chr15[j]&&chr15[j]<850)
		         count[16]++;
	        	if(850<=chr15[j]&&chr15[j]<900)
		         count[17]++;
		        if(900<=chr15[j]&&chr15[j]<950)
		         count[18]++;
		        if(950<=chr15[j]&&chr15[j]<1000)
		         count[19]++;
		        if(1000<=chr15[j]&&chr15[j]<1500)
		          count[20]++;
		        if(1500<=chr15[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==15)
		if(i==16)
		{
			prefix_name+="Chr16_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr16.size();j++)
			{
				if(0<chr16[j]&&chr16[j]<50)
	 	          count[0]++;
		        if(50<=chr16[j]&&chr16[j]<100)
		          count[1]++;
	        	if(100<=chr16[j]&&chr16[j]<150) 
		          count[2]++;
		        if(150<=chr16[j]&&chr16[j]<200) 
		          count[3]++;  
		        if(200<=chr16[j]&&chr16[j]<250) 
		          count[4]++;
	        	if(250<=chr16[j]&&chr16[j]<300) 
		          count[5]++;
		        if(300<=chr16[j]&&chr16[j]<350) 
		         count[6]++;
	            if(350<=chr16[j]&&chr16[j]<400) 
		         count[7]++;
	        	if(400<=chr16[j]&&chr16[j]<450) 
		         count[8]++;
		        if(450<=chr16[j]&&chr16[j]<500) 
		         count[9]++;
	        	if(500<=chr16[j]&&chr16[j]<550) 
		        count[10]++;
		        if(550<=chr16[j]&&chr16[j]<600) 
	  	         count[11]++;
	        	if(600<=chr16[j]&&chr16[j]<650)
		         count[12]++;
		        if(650<=chr16[j]&&chr16[j]<700)
		         count[13]++;
		        if(700<=chr16[j]&&chr16[j]<750)
		         count[14]++;
		       if(750<=chr16[j]&&chr16[j]<800)
		         count[15]++;
		        if(800<=chr16[j]&&chr16[j]<850)
		         count[16]++;
	        	if(850<=chr16[j]&&chr16[j]<900)
		         count[17]++;
		        if(900<=chr16[j]&&chr16[j]<950)
		         count[18]++;
		        if(950<=chr16[j]&&chr16[j]<1000)
		         count[19]++;
		        if(1000<=chr16[j]&&chr16[j]<1500)
		          count[20]++;
		        if(1500<=chr16[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==16)
		if(i==17)
		{
			prefix_name+="Chr17_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr17.size();j++)
			{
				if(0<chr17[j]&&chr17[j]<50)
	 	          count[0]++;
		        if(50<=chr17[j]&&chr17[j]<100)
		          count[1]++;
	        	if(100<=chr17[j]&&chr17[j]<150) 
		          count[2]++;
		        if(150<=chr17[j]&&chr17[j]<200) 
		          count[3]++;  
		        if(200<=chr17[j]&&chr17[j]<250) 
		          count[4]++;
	        	if(250<=chr17[j]&&chr17[j]<300) 
		          count[5]++;
		        if(300<=chr17[j]&&chr17[j]<350) 
		         count[6]++;
	            if(350<=chr17[j]&&chr17[j]<400) 
		         count[7]++;
	        	if(400<=chr17[j]&&chr17[j]<450) 
		         count[8]++;
		        if(450<=chr17[j]&&chr17[j]<500) 
		         count[9]++;
	        	if(500<=chr17[j]&&chr17[j]<550) 
		        count[10]++;
		        if(550<=chr17[j]&&chr17[j]<600) 
	  	         count[11]++;
	        	if(600<=chr17[j]&&chr17[j]<650)
		         count[12]++;
		        if(650<=chr17[j]&&chr17[j]<700)
		         count[13]++;
		        if(700<=chr17[j]&&chr17[j]<750)
		         count[14]++;
		       if(750<=chr17[j]&&chr17[j]<800)
		         count[15]++;
		        if(800<=chr17[j]&&chr17[j]<850)
		         count[16]++;
	        	if(850<=chr17[j]&&chr17[j]<900)
		         count[17]++;
		        if(900<=chr17[j]&&chr17[j]<950)
		         count[18]++;
		        if(950<=chr17[j]&&chr17[j]<1000)
		         count[19]++;
		        if(1000<=chr17[j]&&chr17[j]<1500)
		          count[20]++;
		        if(1500<=chr17[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==17)
		if(i==18)
		{
			prefix_name+="Chr18_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr18.size();j++)
			{
				if(0<chr18[j]&&chr18[j]<50)
	 	          count[0]++;
		        if(50<=chr18[j]&&chr18[j]<100)
		          count[1]++;
	        	if(100<=chr18[j]&&chr18[j]<150) 
		          count[2]++;
		        if(150<=chr18[j]&&chr18[j]<200) 
		          count[3]++;  
		        if(200<=chr18[j]&&chr18[j]<250) 
		          count[4]++;
	        	if(250<=chr18[j]&&chr18[j]<300) 
		          count[5]++;
		        if(300<=chr18[j]&&chr18[j]<350) 
		         count[6]++;
	            if(350<=chr18[j]&&chr18[j]<400) 
		         count[7]++;
	        	if(400<=chr18[j]&&chr18[j]<450) 
		         count[8]++;
		        if(450<=chr18[j]&&chr18[j]<500) 
		         count[9]++;
	        	if(500<=chr18[j]&&chr18[j]<550) 
		        count[10]++;
		        if(550<=chr18[j]&&chr18[j]<600) 
	  	         count[11]++;
	        	if(600<=chr18[j]&&chr18[j]<650)
		         count[12]++;
		        if(650<=chr18[j]&&chr18[j]<700)
		         count[13]++;
		        if(700<=chr18[j]&&chr18[j]<750)
		         count[14]++;
		       if(750<=chr18[j]&&chr18[j]<800)
		         count[15]++;
		        if(800<=chr18[j]&&chr18[j]<850)
		         count[16]++;
	        	if(850<=chr18[j]&&chr18[j]<900)
		         count[17]++;
		        if(900<=chr18[j]&&chr18[j]<950)
		         count[18]++;
		        if(950<=chr18[j]&&chr18[j]<1000)
		         count[19]++;
		        if(1000<=chr18[j]&&chr18[j]<1500)
		          count[20]++;
		        if(1500<=chr18[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==18)
		if(i==19)
		{
			prefix_name+="Chr19_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr19.size();j++)
			{
				if(0<chr19[j]&&chr19[j]<50)
	 	          count[0]++;
		        if(50<=chr19[j]&&chr19[j]<100)
		          count[1]++;
	        	if(100<=chr19[j]&&chr19[j]<150) 
		          count[2]++;
		        if(150<=chr19[j]&&chr19[j]<200) 
		          count[3]++;  
		        if(200<=chr19[j]&&chr19[j]<250) 
		          count[4]++;
	        	if(250<=chr19[j]&&chr19[j]<300) 
		          count[5]++;
		        if(300<=chr19[j]&&chr19[j]<350) 
		         count[6]++;
	            if(350<=chr19[j]&&chr19[j]<400) 
		         count[7]++;
	        	if(400<=chr19[j]&&chr19[j]<450) 
		         count[8]++;
		        if(450<=chr19[j]&&chr19[j]<500) 
		         count[9]++;
	        	if(500<=chr19[j]&&chr19[j]<550) 
		        count[10]++;
		        if(550<=chr19[j]&&chr19[j]<600) 
	  	         count[11]++;
	        	if(600<=chr19[j]&&chr19[j]<650)
		         count[12]++;
		        if(650<=chr19[j]&&chr19[j]<700)
		         count[13]++;
		        if(700<=chr19[j]&&chr19[j]<750)
		         count[14]++;
		       if(750<=chr19[j]&&chr19[j]<800)
		         count[15]++;
		        if(800<=chr19[j]&&chr19[j]<850)
		         count[16]++;
	        	if(850<=chr19[j]&&chr19[j]<900)
		         count[17]++;
		        if(900<=chr19[j]&&chr19[j]<950)
		         count[18]++;
		        if(950<=chr19[j]&&chr19[j]<1000)
		         count[19]++;
		        if(1000<=chr19[j]&&chr19[j]<1500)
		          count[20]++;
		        if(1500<=chr19[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==19)
		if(i==20)
		{
			prefix_name+="Chr20_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr20.size();j++)
			{
			if(0<chr20[j]&&chr20[j]<50)
	 	          count[0]++;
		        if(50<=chr20[j]&&chr20[j]<100)
		          count[1]++;
	        	if(100<=chr20[j]&&chr20[j]<150) 
		          count[2]++;
		        if(150<=chr20[j]&&chr20[j]<200) 
		          count[3]++;  
		        if(200<=chr20[j]&&chr20[j]<250) 
		          count[4]++;
	        	if(250<=chr20[j]&&chr20[j]<300) 
		          count[5]++;
		        if(300<=chr20[j]&&chr20[j]<350) 
		         count[6]++;
	            if(350<=chr20[j]&&chr20[j]<400) 
		         count[7]++;
	        	if(400<=chr20[j]&&chr20[j]<450) 
		         count[8]++;
		        if(450<=chr20[j]&&chr20[j]<500) 
		         count[9]++;
	        	if(500<=chr20[j]&&chr20[j]<550) 
		        count[10]++;
		        if(550<=chr20[j]&&chr20[j]<600) 
	  	         count[11]++;
	        	if(600<=chr20[j]&&chr20[j]<650)
		         count[12]++;
		        if(650<=chr20[j]&&chr20[j]<700)
		         count[13]++;
		        if(700<=chr20[j]&&chr20[j]<750)
		         count[14]++;
		       if(750<=chr20[j]&&chr20[j]<800)
		         count[15]++;
		        if(800<=chr20[j]&&chr20[j]<850)
		         count[16]++;
	        	if(850<=chr20[j]&&chr20[j]<900)
		         count[17]++;
		        if(900<=chr20[j]&&chr20[j]<950)
		         count[18]++;
		        if(950<=chr20[j]&&chr20[j]<1000)
		         count[19]++;
		        if(1000<=chr20[j]&&chr20[j]<1500)
		          count[20]++;
		        if(1500<=chr20[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==20)
		if(i==21)
		{
			prefix_name+="scaffold_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<scaffold.size();j++)
			{
			if(0<scaffold[j]&&scaffold[j]<50)
	 	          count[0]++;
		        if(50<=scaffold[j]&&scaffold[j]<100)
		          count[1]++;
	        	if(100<=scaffold[j]&&scaffold[j]<150) 
		          count[2]++;
		        if(150<=scaffold[j]&&scaffold[j]<200) 
		          count[3]++;  
		        if(200<=scaffold[j]&&scaffold[j]<250) 
		          count[4]++;
	        	if(250<=scaffold[j]&&scaffold[j]<300) 
		          count[5]++;
		        if(300<=scaffold[j]&&scaffold[j]<350) 
		         count[6]++;
	            if(350<=scaffold[j]&&scaffold[j]<400) 
		         count[7]++;
	        	if(400<=scaffold[j]&&scaffold[j]<450) 
		         count[8]++;
		        if(450<=scaffold[j]&&scaffold[j]<500) 
		         count[9]++;
	        	if(500<=scaffold[j]&&scaffold[j]<550) 
		        count[10]++;
		        if(550<=scaffold[j]&&scaffold[j]<600) 
	  	         count[11]++;
	        	if(600<=scaffold[j]&&scaffold[j]<650)
		         count[12]++;
		        if(650<=scaffold[j]&&scaffold[j]<700)
		         count[13]++;
		        if(700<=scaffold[j]&&scaffold[j]<750)
		         count[14]++;
		       if(750<=scaffold[j]&&scaffold[j]<800)
		         count[15]++;
		        if(800<=scaffold[j]&&scaffold[j]<850)
		         count[16]++;
	        	if(850<=scaffold[j]&&scaffold[j]<900)
		         count[17]++;
		        if(900<=scaffold[j]&&scaffold[j]<950)
		         count[18]++;
		        if(950<=scaffold[j]&&scaffold[j]<1000)
		         count[19]++;
		        if(1000<=scaffold[j]&&scaffold[j]<1500)
		          count[20]++;
		        if(1500<=scaffold[j]&&scaffold[j])
		          count[21]++;
		
         	}
       	    for(int h=0;h<22;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 50: "<<count[0]<<endl<<"50 to 100:"<<count[1]<<endl;
            w_file<<"100to 150:"<<count[2]<<endl<<"150 to 200:"<<count[3]<<endl;
            w_file<<"200 to 250:"<<count[4]<<endl<<"250 to 300:"<<count[5]<<endl;
            w_file<<"300 to 350:"<<count[6]<<endl<<"350 to 400:"<<count[7]<<endl;
	        w_file<<"400 to 450:"<<count[8]<<endl<<"450 to 500:"<<count[9]<<endl;
	        w_file<<"500 to 550:"<<count[10]<<endl<<"550 to 600:"<<count[11]<<endl;	
	        w_file<<"600 to 650:"<<count[12]<<endl<<"650 to 700:"<<count[13]<<endl;
	        w_file<<"700 to 750:"<<count[14]<<endl<<"750 to 800:"<<count[15]<<endl;
	        w_file<<"800 to 850:"<<count[16]<<endl<<"850 to 900:"<<count[17]<<endl;
	        w_file<<"900 to 950:"<<count[18]<<endl<<"950 to 1000:"<<count[19]<<endl;
	        w_file<<"1000 to 1500:"<<count[20]<<endl<<"greater or equall than 1500:"<<count[21]<<endl;
			w_file.close();
			
			for(int k=0;k<22;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==21)
	}
	
	
	
	
	
	read_file.close();
	write_file.close();
	cout<<"The program execute successfully."<<endl;
	return 0;
	
}	
	
/*	
	ofstream w_file;
	for(int kk=0;kk<22;kk++)
    count[kk]=0;
	for(int i=1;i<=21;i++) 
	{
		if(i==1)
		{
			prefix_name+="Chr01_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr1.size();j++)
			{
				if(0<chr1[j]&&chr1[j]<100)
		          count[0]++;
		        if(100<=chr1[j]&&chr1[j]<200)
		          count[1]++;
	        	if(200<=chr1[j]&&chr1[j]<300) 
		         count[2]++;
		        if(300<=chr1[j]&&chr1[j]<400) 
		           count[3]++;  
		        if(400<=chr1[j]&&chr1[j]<500) 
		         count[4]++;
	         	if(500<=chr1[j]&&chr1[j]<600) 
		         count[5]++;
	         	if(600<=chr1[j]&&chr1[j]<700) 
		         count[6]++;
	            if(700<=chr1[j]&&chr1[j]<800) 
		         count[7]++;
		        if(800<=chr1[j]&&chr1[j]<900) 
		          count[8]++;
		        if(900<=chr1[j]&&chr1[j]<1000) 
		          count[9]++;
	         	if(1000<chr1[j]&&chr1[j]<2000) 
		         count[10]++;
		        if(2000<=chr1[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
	    	prefix_name.clear();
		}
			if(i==2)
		{
			prefix_name+="Chr02_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr2.size();j++)
			{
				if(0<chr2[j]&&chr2[j]<100)
		          count[0]++;
		        if(100<=chr2[j]&&chr2[j]<200)
		          count[1]++;
	        	if(200<=chr2[j]&&chr2[j]<300) 
		         count[2]++;
		        if(300<=chr2[j]&&chr2[j]<400) 
		           count[3]++;  
		        if(400<=chr2[j]&&chr2[j]<500) 
		         count[4]++;
	         	if(500<=chr2[j]&&chr2[j]<600) 
		         count[5]++;
	         	if(600<=chr2[j]&&chr2[j]<700) 
		         count[6]++;
	            if(700<=chr2[j]&&chr2[j]<800) 
		         count[7]++;
		        if(800<=chr2[j]&&chr2[j]<900) 
		          count[8]++;
		        if(900<=chr2[j]&&chr2[j]<1000) 
		          count[9]++;
	         	if(1000<chr2[j]&&chr2[j]<2000) 
		         count[10]++;
		        if(2000<=chr2[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		   prefix_name.clear();
		}//if(i==2)
			if(i==3)
		{
			prefix_name+="Chr03_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr3.size();j++)
			{
				if(0<chr3[j]&&chr3[j]<100)
		          count[0]++;
		        if(100<=chr3[j]&&chr3[j]<200)
		          count[1]++;
	        	if(200<=chr3[j]&&chr3[j]<300) 
		         count[2]++;
		        if(300<=chr3[j]&&chr3[j]<400) 
		           count[3]++;  
		        if(400<=chr3[j]&&chr3[j]<500) 
		         count[4]++;
	         	if(500<=chr3[j]&&chr3[j]<600) 
		         count[5]++;
	         	if(600<=chr3[j]&&chr3[j]<700) 
		         count[6]++;
	            if(700<=chr3[j]&&chr3[j]<800) 
		         count[7]++;
		        if(800<=chr3[j]&&chr3[j]<900) 
		          count[8]++;
		        if(900<=chr3[j]&&chr3[j]<1000) 
		          count[9]++;
	         	if(1000<chr3[j]&&chr3[j]<2000) 
		         count[10]++;
		        if(2000<=chr3[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==3)
		
			if(i==4)
		{
			prefix_name+="Chr04_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr4.size();j++)
			{
				if(0<chr4[j]&&chr4[j]<100)
		          count[0]++;
		        if(100<=chr4[j]&&chr4[j]<200)
		          count[1]++;
	        	if(200<=chr4[j]&&chr4[j]<300) 
		         count[2]++;
		        if(300<=chr4[j]&&chr4[j]<400) 
		           count[3]++;  
		        if(400<=chr4[j]&&chr4[j]<500) 
		         count[4]++;
	         	if(500<=chr4[j]&&chr4[j]<600) 
		         count[5]++;
	         	if(600<=chr4[j]&&chr4[j]<700) 
		         count[6]++;
	            if(700<=chr4[j]&&chr4[j]<800) 
		         count[7]++;
		        if(800<=chr4[j]&&chr4[j]<900) 
		          count[8]++;
		        if(900<=chr4[j]&&chr4[j]<1000) 
		          count[9]++;
	         	if(1000<chr4[j]&&chr4[j]<2000) 
		         count[10]++;
		        if(2000<=chr4[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==4)
			if(i==5)
		{
			prefix_name+="Chr05_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr5.size();j++)
			{
				if(0<chr5[j]&&chr5[j]<100)
		          count[0]++;
		        if(100<=chr5[j]&&chr5[j]<200)
		          count[1]++;
	        	if(200<=chr5[j]&&chr5[j]<300) 
		         count[2]++;
		        if(300<=chr5[j]&&chr5[j]<400) 
		           count[3]++;  
		        if(400<=chr5[j]&&chr5[j]<500) 
		         count[4]++;
	         	if(500<=chr5[j]&&chr5[j]<600) 
		         count[5]++;
	         	if(600<=chr5[j]&&chr5[j]<700) 
		         count[6]++;
	            if(700<=chr5[j]&&chr5[j]<800) 
		         count[7]++;
		        if(800<=chr5[j]&&chr5[j]<900) 
		          count[8]++;
		        if(900<=chr5[j]&&chr5[j]<1000) 
		          count[9]++;
	         	if(1000<chr5[j]&&chr5[j]<2000) 
		         count[10]++;
		        if(2000<=chr5[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==5)
			if(i==6)
		{
			prefix_name+="Chr06_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr6.size();j++)
			{
				if(0<chr6[j]&&chr6[j]<100)
		          count[0]++;
		        if(100<=chr6[j]&&chr6[j]<200)
		          count[1]++;
	        	if(200<=chr6[j]&&chr6[j]<300) 
		         count[2]++;
		        if(300<=chr6[j]&&chr6[j]<400) 
		           count[3]++;  
		        if(400<=chr6[j]&&chr6[j]<500) 
		         count[4]++;
	         	if(500<=chr6[j]&&chr6[j]<600) 
		         count[5]++;
	         	if(600<=chr6[j]&&chr6[j]<700) 
		         count[6]++;
	            if(700<=chr6[j]&&chr6[j]<800) 
		         count[7]++;
		        if(800<=chr6[j]&&chr6[j]<900) 
		          count[8]++;
		        if(900<=chr6[j]&&chr6[j]<1000) 
		          count[9]++;
	         	if(1000<chr6[j]&&chr6[j]<2000) 
		         count[10]++;
		        if(2000<=chr6[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i=6)
			if(i==7)
		{
			prefix_name+="Chr07_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr7.size();j++)
			{
				if(0<chr7[j]&&chr7[j]<100)
		          count[0]++;
		        if(100<=chr7[j]&&chr7[j]<200)
		          count[1]++;
	        	if(200<=chr7[j]&&chr7[j]<300) 
		         count[2]++;
		        if(300<=chr7[j]&&chr7[j]<400) 
		           count[3]++;  
		        if(400<=chr7[j]&&chr7[j]<500) 
		         count[4]++;
	         	if(500<=chr7[j]&&chr7[j]<600) 
		         count[5]++;
	         	if(600<=chr7[j]&&chr7[j]<700) 
		         count[6]++;
	            if(700<=chr7[j]&&chr7[j]<800) 
		         count[7]++;
		        if(800<=chr7[j]&&chr7[j]<900) 
		          count[8]++;
		        if(900<=chr7[j]&&chr7[j]<1000) 
		          count[9]++;
	         	if(1000<chr7[j]&&chr7[j]<2000) 
		         count[10]++;
		        if(2000<=chr7[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==7)
			if(i==8)
		{
			prefix_name+="Chr08_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr8.size();j++)
			{
				if(0<chr8[j]&&chr8[j]<100)
		          count[0]++;
		        if(100<=chr8[j]&&chr8[j]<200)
		          count[1]++;
	        	if(200<=chr8[j]&&chr8[j]<300) 
		         count[2]++;
		        if(300<=chr8[j]&&chr8[j]<400) 
		           count[3]++;  
		        if(400<=chr8[j]&&chr8[j]<500) 
		         count[4]++;
	         	if(500<=chr8[j]&&chr8[j]<600) 
		         count[5]++;
	         	if(600<=chr8[j]&&chr8[j]<700) 
		         count[6]++;
	            if(700<=chr8[j]&&chr8[j]<800) 
		         count[7]++;
		        if(800<=chr8[j]&&chr8[j]<900) 
		          count[8]++;
		        if(900<=chr8[j]&&chr8[j]<1000) 
		          count[9]++;
	         	if(1000<chr8[j]&&chr8[j]<2000) 
		         count[10]++;
		        if(2000<=chr8[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==8)
			if(i==9)
		{
			prefix_name+="Chr09_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr9.size();j++)
			{
				if(0<chr9[j]&&chr9[j]<100)
		          count[0]++;
		        if(100<=chr9[j]&&chr9[j]<200)
		          count[1]++;
	        	if(200<=chr9[j]&&chr9[j]<300) 
		         count[2]++;
		        if(300<=chr9[j]&&chr9[j]<400) 
		           count[3]++;  
		        if(400<=chr9[j]&&chr9[j]<500) 
		         count[4]++;
	         	if(500<=chr9[j]&&chr9[j]<600) 
		         count[5]++;
	         	if(600<=chr9[j]&&chr9[j]<700) 
		         count[6]++;
	            if(700<=chr9[j]&&chr9[j]<800) 
		         count[7]++;
		        if(800<=chr9[j]&&chr9[j]<900) 
		          count[8]++;
		        if(900<=chr9[j]&&chr9[j]<1000) 
		          count[9]++;
	         	if(1000<chr9[j]&&chr9[j]<2000) 
		         count[10]++;
		        if(2000<=chr9[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==9)
			if(i==10)
		{
			prefix_name+="Chr10_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr10.size();j++)
			{
				if(0<chr10[j]&&chr10[j]<100)
		          count[0]++;
		        if(100<=chr10[j]&&chr10[j]<200)
		          count[1]++;
	        	if(200<=chr10[j]&&chr10[j]<300) 
		         count[2]++;
		        if(300<=chr10[j]&&chr10[j]<400) 
		           count[3]++;  
		        if(400<=chr10[j]&&chr10[j]<500) 
		         count[4]++;
	         	if(500<=chr10[j]&&chr10[j]<600) 
		         count[5]++;
	         	if(600<=chr10[j]&&chr10[j]<700) 
		         count[6]++;
	            if(700<=chr10[j]&&chr10[j]<800) 
		         count[7]++;
		        if(800<=chr10[j]&&chr10[j]<900) 
		          count[8]++;
		        if(900<=chr10[j]&&chr10[j]<1000) 
		          count[9]++;
	         	if(1000<chr10[j]&&chr10[j]<2000) 
		         count[10]++;
		        if(2000<=chr10[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==10)
			if(i==11)
		{
			prefix_name+="Chr11_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr11.size();j++)
			{
				if(0<chr11[j]&&chr11[j]<100)
		          count[0]++;
		        if(100<=chr11[j]&&chr11[j]<200)
		          count[1]++;
	        	if(200<=chr11[j]&&chr11[j]<300) 
		         count[2]++;
		        if(300<=chr11[j]&&chr11[j]<400) 
		           count[3]++;  
		        if(400<=chr11[j]&&chr11[j]<500) 
		         count[4]++;
	         	if(500<=chr11[j]&&chr11[j]<600) 
		         count[5]++;
	         	if(600<=chr11[j]&&chr11[j]<700) 
		         count[6]++;
	            if(700<=chr11[j]&&chr11[j]<800) 
		         count[7]++;
		        if(800<=chr11[j]&&chr11[j]<900) 
		          count[8]++;
		        if(900<=chr11[j]&&chr11[j]<1000) 
		          count[9]++;
	         	if(1000<chr11[j]&&chr11[j]<2000) 
		         count[10]++;
		        if(2000<=chr11[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==11)
		if(i==12)
		{
			prefix_name+="Chr12_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr12.size();j++)
			{
				if(0<chr12[j]&&chr12[j]<100)
		          count[0]++;
		        if(100<=chr12[j]&&chr12[j]<200)
		          count[1]++;
	        	if(200<=chr12[j]&&chr12[j]<300) 
		         count[2]++;
		        if(300<=chr12[j]&&chr12[j]<400) 
		           count[3]++;  
		        if(400<=chr12[j]&&chr12[j]<500) 
		         count[4]++;
	         	if(500<=chr12[j]&&chr12[j]<600) 
		         count[5]++;
	         	if(600<=chr12[j]&&chr12[j]<700) 
		         count[6]++;
	            if(700<=chr12[j]&&chr12[j]<800) 
		         count[7]++;
		        if(800<=chr12[j]&&chr12[j]<900) 
		          count[8]++;
		        if(900<=chr12[j]&&chr12[j]<1000) 
		          count[9]++;
	         	if(1000<chr12[j]&&chr12[j]<2000) 
		         count[10]++;
		        if(2000<=chr12[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==12)
		if(i==13)
		{
			prefix_name+="Chr13_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr13.size();j++)
			{
				if(0<chr13[j]&&chr13[j]<100)
		          count[0]++;
		        if(100<=chr13[j]&&chr13[j]<200)
		          count[1]++;
	        	if(200<=chr13[j]&&chr13[j]<300) 
		         count[2]++;
		        if(300<=chr13[j]&&chr13[j]<400) 
		           count[3]++;  
		        if(400<=chr13[j]&&chr13[j]<500) 
		         count[4]++;
	         	if(500<=chr13[j]&&chr13[j]<600) 
		         count[5]++;
	         	if(600<=chr13[j]&&chr13[j]<700) 
		         count[6]++;
	            if(700<=chr13[j]&&chr13[j]<800) 
		         count[7]++;
		        if(800<=chr13[j]&&chr13[j]<900) 
		          count[8]++;
		        if(900<=chr13[j]&&chr13[j]<1000) 
		          count[9]++;
	         	if(1000<chr13[j]&&chr13[j]<2000) 
		         count[10]++;
		        if(2000<=chr13[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==13)
		if(i==14)
		{
			prefix_name+="Chr14_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr14.size();j++)
			{
				if(0<chr14[j]&&chr14[j]<100)
		          count[0]++;
		        if(100<=chr14[j]&&chr14[j]<200)
		          count[1]++;
	        	if(200<=chr14[j]&&chr14[j]<300) 
		         count[2]++;
		        if(300<=chr14[j]&&chr14[j]<400) 
		           count[3]++;  
		        if(400<=chr14[j]&&chr14[j]<500) 
		         count[4]++;
	         	if(500<=chr14[j]&&chr14[j]<600) 
		         count[5]++;
	         	if(600<=chr14[j]&&chr14[j]<700) 
		         count[6]++;
	            if(700<=chr14[j]&&chr14[j]<800) 
		         count[7]++;
		        if(800<=chr14[j]&&chr14[j]<900) 
		          count[8]++;
		        if(900<=chr14[j]&&chr14[j]<1000) 
		          count[9]++;
	         	if(1000<chr14[j]&&chr14[j]<2000) 
		         count[10]++;
		        if(2000<=chr14[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==14)
		if(i==15)
		{
			prefix_name+="Chr15_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr15.size();j++)
			{
				if(0<chr15[j]&&chr15[j]<100)
		          count[0]++;
		        if(100<=chr15[j]&&chr15[j]<200)
		          count[1]++;
	        	if(200<=chr15[j]&&chr15[j]<300) 
		         count[2]++;
		        if(300<=chr15[j]&&chr15[j]<400) 
		           count[3]++;  
		        if(400<=chr15[j]&&chr15[j]<500) 
		         count[4]++;
	         	if(500<=chr15[j]&&chr15[j]<600) 
		         count[5]++;
	         	if(600<=chr15[j]&&chr15[j]<700) 
		         count[6]++;
	            if(700<=chr15[j]&&chr15[j]<800) 
		         count[7]++;
		        if(800<=chr15[j]&&chr15[j]<900) 
		          count[8]++;
		        if(900<=chr15[j]&&chr15[j]<1000) 
		          count[9]++;
	         	if(1000<chr15[j]&&chr15[j]<2000) 
		         count[10]++;
		        if(2000<=chr15[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==15)
		if(i==16)
		{
			prefix_name+="Chr16_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr16.size();j++)
			{
				if(0<chr16[j]&&chr16[j]<100)
		          count[0]++;
		        if(100<=chr16[j]&&chr16[j]<200)
		          count[1]++;
	        	if(200<=chr16[j]&&chr16[j]<300) 
		         count[2]++;
		        if(300<=chr16[j]&&chr16[j]<400) 
		           count[3]++;  
		        if(400<=chr16[j]&&chr16[j]<500) 
		         count[4]++;
	         	if(500<=chr16[j]&&chr16[j]<600) 
		         count[5]++;
	         	if(600<=chr16[j]&&chr16[j]<700) 
		         count[6]++;
	            if(700<=chr16[j]&&chr16[j]<800) 
		         count[7]++;
		        if(800<=chr16[j]&&chr16[j]<900) 
		          count[8]++;
		        if(900<=chr16[j]&&chr16[j]<1000) 
		          count[9]++;
	         	if(1000<chr16[j]&&chr16[j]<2000) 
		         count[10]++;
		        if(2000<=chr16[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==16)
		if(i==17)
		{
			prefix_name+="Chr17_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr17.size();j++)
			{
				if(0<chr17[j]&&chr17[j]<100)
		          count[0]++;
		        if(100<=chr17[j]&&chr17[j]<200)
		          count[1]++;
	        	if(200<=chr17[j]&&chr17[j]<300) 
		         count[2]++;
		        if(300<=chr17[j]&&chr17[j]<400) 
		           count[3]++;  
		        if(400<=chr17[j]&&chr17[j]<500) 
		         count[4]++;
	         	if(500<=chr17[j]&&chr17[j]<600) 
		         count[5]++;
	         	if(600<=chr17[j]&&chr17[j]<700) 
		         count[6]++;
	            if(700<=chr17[j]&&chr17[j]<800) 
		         count[7]++;
		        if(800<=chr17[j]&&chr17[j]<900) 
		          count[8]++;
		        if(900<=chr17[j]&&chr17[j]<1000) 
		          count[9]++;
	         	if(1000<chr17[j]&&chr17[j]<2000) 
		         count[10]++;
		        if(2000<=chr17[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==17)
		if(i==18)
		{
			prefix_name+="Chr18_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr18.size();j++)
			{
				if(0<chr18[j]&&chr18[j]<100)
		          count[0]++;
		        if(100<=chr18[j]&&chr18[j]<200)
		          count[1]++;
	        	if(200<=chr18[j]&&chr18[j]<300) 
		         count[2]++;
		        if(300<=chr18[j]&&chr18[j]<400) 
		           count[3]++;  
		        if(400<=chr18[j]&&chr18[j]<500) 
		         count[4]++;
	         	if(500<=chr18[j]&&chr18[j]<600) 
		         count[5]++;
	         	if(600<=chr18[j]&&chr18[j]<700) 
		         count[6]++;
	            if(700<=chr18[j]&&chr18[j]<800) 
		         count[7]++;
		        if(800<=chr18[j]&&chr18[j]<900) 
		          count[8]++;
		        if(900<=chr18[j]&&chr18[j]<1000) 
		          count[9]++;
	         	if(1000<chr18[j]&&chr18[j]<2000) 
		         count[10]++;
		        if(2000<=chr18[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==18)
		if(i==19)
		{
			prefix_name+="Chr19_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr19.size();j++)
			{
				if(0<chr19[j]&&chr19[j]<100)
		          count[0]++;
		        if(100<=chr19[j]&&chr19[j]<200)
		          count[1]++;
	        	if(200<=chr19[j]&&chr19[j]<300) 
		         count[2]++;
		        if(300<=chr19[j]&&chr19[j]<400) 
		           count[3]++;  
		        if(400<=chr19[j]&&chr19[j]<500) 
		         count[4]++;
	         	if(500<=chr19[j]&&chr19[j]<600) 
		         count[5]++;
	         	if(600<=chr19[j]&&chr19[j]<700) 
		         count[6]++;
	            if(700<=chr19[j]&&chr19[j]<800) 
		         count[7]++;
		        if(800<=chr19[j]&&chr19[j]<900) 
		          count[8]++;
		        if(900<=chr19[j]&&chr19[j]<1000) 
		          count[9]++;
	         	if(1000<chr19[j]&&chr19[j]<2000) 
		         count[10]++;
		        if(2000<=chr19[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==19)
		if(i==20)
		{
			prefix_name+="Chr20_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<chr20.size();j++)
			{
				if(0<chr20[j]&&chr20[j]<100)
		          count[0]++;
		        if(100<=chr20[j]&&chr20[j]<200)
		          count[1]++;
	        	if(200<=chr20[j]&&chr20[j]<300) 
		         count[2]++;
		        if(300<=chr20[j]&&chr20[j]<400) 
		           count[3]++;  
		        if(400<=chr20[j]&&chr20[j]<500) 
		         count[4]++;
	         	if(500<=chr20[j]&&chr20[j]<600) 
		         count[5]++;
	         	if(600<=chr20[j]&&chr20[j]<700) 
		         count[6]++;
	            if(700<=chr20[j]&&chr20[j]<800) 
		         count[7]++;
		        if(800<=chr20[j]&&chr20[j]<900) 
		          count[8]++;
		        if(900<=chr20[j]&&chr20[j]<1000) 
		          count[9]++;
	         	if(1000<chr20[j]&&chr20[j]<2000) 
		         count[10]++;
		        if(2000<=chr20[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==20)
		if(i==21)
		{
			prefix_name+="scaffold_statistic_range.txt";
			w_file.open(prefix_name.c_str());
			
			for(long int j=0;j<scaffold.size();j++)
			{
				if(0<scaffold[j]&&scaffold[j]<100)
		          count[0]++;
		        if(100<=scaffold[j]&&scaffold[j]<200)
		          count[1]++;
	        	if(200<=scaffold[j]&&scaffold[j]<300) 
		         count[2]++;
		        if(300<=scaffold[j]&&scaffold[j]<400) 
		           count[3]++;  
		        if(400<=scaffold[j]&&scaffold[j]<500) 
		         count[4]++;
	         	if(500<=scaffold[j]&&scaffold[j]<600) 
		         count[5]++;
	         	if(600<=scaffold[j]&&scaffold[j]<700) 
		         count[6]++;
	            if(700<=scaffold[j]&&scaffold[j]<800) 
		         count[7]++;
		        if(800<=scaffold[j]&&scaffold[j]<900) 
		          count[8]++;
		        if(900<=scaffold[j]&&scaffold[j]<1000) 
		          count[9]++;
	         	if(1000<scaffold[j]&&scaffold[j]<2000) 
		         count[10]++;
		        if(2000<=scaffold[j]) 
		           count[11]++;
         	}
       	    for(int h=0;h<12;h++)
         	{
		       w_file<<count[h]<<endl;
	        }
	        w_file<<"\n\n"<<"the segment totaol:"<<endl;
            w_file<<"0 to 100: "<<count[0]<<endl<<"100 to 200:"<<count[1]<<endl;
	        w_file<<"200 to 300:"<<count[2]<<endl<<"300 to 400:"<<count[3]<<endl;
            w_file<<"400 to 500:"<<count[4]<<endl<<"500 to 600:"<<count[5]<<endl;
	        w_file<<"600 to 700:"<<count[6]<<endl<<"700 to 800:"<<count[7]<<endl;
	        w_file<<"800 to 900:"<<count[8]<<endl<<"900 to 1000:"<<count[9]<<endl;
	        w_file<<"1000 to 2000:"<<count[10]<<endl<<"greater than 2000:"<<count[11]<<endl;	
			w_file.close();
			
			for(int k=0;k<12;k++)
			    count[k]=0;
		//	cout<<"count[0]"<<count[0]<<endl;
		prefix_name.clear();
		}//if(i==21)
	}
 
*/
		
		
	


