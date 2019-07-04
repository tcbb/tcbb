#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>


using namespace std;
int main()
{
	ifstream read_file;
	string read_file_name="F:\\simulate_data\\Chr15.fa";
	read_file.open(read_file_name.c_str());
	if(!read_file)
	{
		cout<<"This file can not open"<<endl;
		exit(1);
	}
	cout<<"This parogram start. .........."<<endl;
	ofstream write_file;
	string write_file_name="F:\\simulate_data\\Chr15_length.txt";
	write_file.open(write_file_name.c_str());
	string line;
	vector <char > c;
	char ch;
	long long int i=0;
	while((ch=read_file.get())!=EOF)
	{
		i++;
		c.push_back(ch);
		
	}
	write_file<<">Chr15  "<<"Its length is:"<<i<<endl;
	for(long long int j=0;j<c.size();j++)
	   write_file<<c[j];
	write_file<<endl;
	
	
	 read_file.clear();
	 write_file.close();
	 cout<<"This program finish."<<endl;
	/* 
	getline(read_file,line);
	vector <int > length;
	while(getline(read_file,line))
	{
		i++;
		length.push_back(line.size());
	}
	sort(length.begin(),length.end());
	
	long long sum=0;
	for(long int i=0;i<length.size();i++)
	{
		sum+=length[i];
	}
	long int average=(sum)/(length.size());
	write_file<<"The total number is:"<<i<<"\t\t"<<"The average of the length is:"<<average<<endl;
	write_file<<"The maximum length is:"<<length[length.size()-1]<<"\t\t"<<"The mimium length is:"<<length[0]<<endl;
	write_file<<"belwo the read length:"<<endl;
	for(long int j=0;j<length.size();j++)
	  write_file<<length[j]<<endl;
	
	
	read_file.close();
	write_file.close();
	cout<<"The program finish successfully!!!"<<endl;
	*/
	
	return 0;
 } 
