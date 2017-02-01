

#ifndef creatfile_h
#define creatfile_h
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
string inputConect;
void inputConent(){
    cout<<"Please enter text content!(end of '#')"<<endl;
    char x;
    while ((x=cin.get())!='#') {
        inputConect+=x;
    }
    cout<<inputConect<<endl;
}
void creatFile(){
    char fileName[20];
    inputConent();
    FILE *fp;
    cout<<"please input file name:";
    cin>>fileName;
    fp = fopen(fileName,"w+");
    fclose(fp);
    ofstream infile(fileName,ios::in);
    if(!infile){
        cout<<"error"<<endl;
    }
    else{
        infile<<inputConect<<endl;
        inputConect = "";   //Empty string after writing to the file
    }
}


#endif /* creatfile_h */
