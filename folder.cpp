#include<iostream>
#include <ctime>
#include <cstdlib>
#include<stdlib.h>
#include"folder.h"
#include"OutputFile.h"
using namespace std;
void Files::getFormat()
{
    ifstream  readFile;
    for(int i=0;i<fileNum;i++)
    {
        int l=files_path[i].length();
        if(files_path[i][l-1]=='t')
        {
            readFile.open(files_path[i]);
        }
    }  
    std::stringstream  streambuffer;  
    streambuffer<<readFile.rdbuf(); 
    string sdata(streambuffer.str());  
    inputFormatNum=0;
    stringstream input;
    input<<sdata;
    string result;
    while(input>>result)
    {
        format.push_back(result);
    }
    input.clear(ios::goodbit);
    inputFormatNum=format.size();
    //cout<<inputFormatNum<<endl;
    // for(int j=0;j<inputFormatNum;j++)
    // {
    //     cout<<format[j]<<endl;
    // }
    

}
void Files::randomSample(int n)
{
    ofstream ofs;
    ofs.open("input.txt", ios::out);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<inputFormatNum;j++)
        {

            //cout<<format[j]<<endl;
            if(format[j][0]=='i')
            {
                //int(12,100)
                int ind=format[j].find(',');
                string sa=format[j].substr(4,ind-4);
                string sb=format[j].substr(ind+1,format[j].length()-2-ind);
                int a = atoi(sa.c_str());
                int b = atoi(sb.c_str());
                srand(time(0) * (i+1));
                int sample=rand() % (b - a + 1) + a;
                //cout<<sample<<endl;
                ofs<< sample<<" " ;
            }
            else if(format[j][0]=='c')
            {
                //char
                srand(time(0) * (i+1));
                char c = 'a' + rand() % 26;
                //cout<<c<<endl;
                string inputname;
                inputname=to_string(n)+"input.txt";
                ofs<< c<<" " ;
                
            }
            else if(format[j][0]=='s')
            {
                //string(12,100)
                int ind=format[j].find(',');
                string sa=format[j].substr(7,ind-7);
                string sb=format[j].substr(ind+1,format[j].length()-2-ind);
                int a = atoi(sa.c_str());
                int b = atoi(sb.c_str());
                srand(time(0) * (i+1));
                int samplelength=rand() % (b - a + 1) + a;
                string sam;
                char cc;
                for(int k=0;k<samplelength;k++)
                {
                    cc='a'+rand()%26;
                    sam.push_back(cc);
                }
                //cout<<sam<<endl;
                
                ofs<< sam<<" " ;
                
            }
            
        }
        ofs<<endl;
        
    }

    ofs.close();
}
void Files::runoj(int n)
{

    string res=files_path[n].substr(0,files_path[n].find('.'))+".txt";
    //cout<<res<<endl;
    ofstream outfile(res);
    outfile.close();
    //cout<<files_path[n]<<endl;
    string name=files_path[n].substr(0,files_path[n].find('.'));
    string cmd1="g++ -std=c++14 "+files_path[n]+" -o "+name+".out";
    //cout<<cmd1<<endl;
    system(cmd1.c_str());
    ifstream in("input.txt");
    string s1;
    getline(in,s1);
    while(in)
    {
        ofstream out1("in.txt");
        out1<<s1<<endl;
        out1.close();
        string cmd2=name+".out <in.txt >ou.txt";
        system(cmd2.c_str());
        string s2;
        ifstream in2("ou.txt");
        getline(in2,s2);
        in2.close();
        ofstream out2(res,ios::app);
        out2<<s2;
        getline(in,s1);
        if(in) out2<<endl;
        out2.close();
    }
    in.close();
    string cmd3="rm "+name+".out";
    system(cmd3.c_str());
    system("rm in.txt");
    system("rm ou.txt");
}

void Files::JudgeOJ()
{
    vector<string> names;
    for(int i=0;i<fileNum;i++)
    {
        int l=files_path[i].length()-1;
        if(files_path[i][l]=='p')
        {
            string res=files_path[i].substr(0,files_path[i].find('.'))+".txt";
            names.push_back(res);
        }
    }
    for(int i=0;i<fileNum-1;i++)
    {
        ifstream f1(names[i]);
        stringstream buffer;
        buffer<<f1.rdbuf();
        string contents(buffer.str());
        f1.close();
        for(int j=i+1;j<fileNum-1;j++)
        {
            ifstream f2(names[j]);
            stringstream buffer2;
            buffer2<<f2.rdbuf();
            string contents2(buffer2.str());
            f2.close();
            MyOutput o;
            if(contents==contents2)
            {
                
                o.writeOut(names[i],names[j],1);
            }
            else{
                
                o.writeOut(names[i],names[j],0);
            }
        }
    }
}

void GetFileNames(string path,vector<string>& filenames,int &num1)
{
    num1=0;
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str())))
    {
        cout<<"Folder doesn't Exist!"<<endl;
        return;
    }
    while((ptr = readdir(pDir))!=0) 
    {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
        {
            filenames.push_back(path + "/" + ptr->d_name);
            num1++;
        }
    }
    closedir(pDir);
}