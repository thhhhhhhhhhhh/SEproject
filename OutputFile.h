
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include <stdio.h>
#include <fstream>

#include <sstream>
using namespace std;
class MyOutput
{
private:
    int flag;
    string sa;
    string sb;
public:
    friend class Files; 
    MyOutput(){};
    ~MyOutput(){};
    void writeOut(string a,string b,int f);
};