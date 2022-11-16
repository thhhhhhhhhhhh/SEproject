#include<iostream>

#include"folder.h"

using namespace std;


int main()
{
    cout<<"Please input the path of the folder you want to open:";
    string path;
    cin>>path;
    //string path = "/home/th/input";
    Folder folder;
    
    GetFileNames(path, folder.files_name,folder.folderNum);
    for(int i = 0; i <folder.files_name.size(); i++)
    {
        Files *file=new Files;
        GetFileNames(folder.files_name[i],file->files_path,file->fileNum);
        file->getFormat();    
        file->randomSample(i);
        for(int j=0;j<file->fileNum;j++)
        {
            int l=file->files_path[j].length()-1;
            if(file->files_path[j][l]=='p')
            {
                //cout<<"run"<<endl;
                file->runoj(j);
            }
      
        }
        file->JudgeOJ();
    }

    return 0;
}