
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>

#include <sstream>

using namespace std;

class Folder
{
public:
    vector<string> files_name;
    vector<string> format;
    int folderNum;
    Folder(){};
    ~Folder(){};
};
class Files
{
public:
    
    vector<string> files_path;
    int fileNum;
    vector<string> format;
    int inputFormatNum;
    void getFormat();
    void randomSample(int n);
    void runoj(int n);
    void JudgeOJ();
    //void writeOut(string a,string b,int flag);
    Files(){};
    ~Files(){};
};

void GetFileNames(string path,vector<string>& filenames,int &num1);
