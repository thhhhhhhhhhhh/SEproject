#include<iostream>
#include"OutputFile.h"

using namespace std;
void MyOutput::writeOut(string a,string b,int f)
{
    flag=f;
    string f1=a.substr(0,a.find('.'))+".cpp";
    string f2=b.substr(0,b.find('.'))+".cpp";
    int ind1=0;
    for(int i=0;i<f1.length()-1;i++)
    {
        if(f1[i]=='/'&&f1[i+1]=='i'&&f1[i+2]=='n'&&f1[i+3]=='p'&&f1[i+4]=='u'&&f1[i+5]=='t'&&f1[i+6]=='/')
        {
            ind1=i;
            break;
        }
    }
    sa=f1.substr(ind1+1,f1.length()-ind1);
    sb=f2.substr(ind1+1,f2.length()-ind1);
    if(flag==1)
    {
        ofstream outFile;
        outFile.open("equal.csv",ios::app);
        outFile << sa<<","<<sb<<endl;
    }
    else if(flag==0)
    {
        ofstream outFile;
        outFile.open("inequal.csv",ios::app);
        outFile << sa<<","<<sb<<endl;
    }
}