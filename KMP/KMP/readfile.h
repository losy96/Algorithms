
#ifndef readfile_h
#define readfile_h
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
char readFileName[20];
void inputFileName(){
    cout<<"please input file name:";
    cin>>readFileName;

}
int articleLong(){   //∂¡»°Œƒº˛÷–◊÷∑˚ ˝
    char ch;
    int i;
    inputFileName();
    FILE *fp;
    fp = fopen(readFileName,"r");
    if(!fp){
        cout<<"File not open!";
        exit(0);
    }
    else{
        i=0;
        ch = fgetc(fp);
        while(ch != EOF){
            ch = fgetc(fp);
            i++;
        }
    }
    fclose(fp);
    return i;
}
void readFile( char * article){ //¥”Œƒº˛÷–Ω´◊÷∑˚¥Æ∂¡»Îarticle ˝◊È÷–
    char ch;
    FILE *fp;
    fp = fopen(readFileName,"r");
    if(!fp){
        cout<<"File not open!";
        exit(0);
    }
    else{
        int i=0;
        ch = fgetc(fp);
        while(ch != EOF){
            article[i] = ch;
            ch = fgetc(fp);
            i++;
        }
    }
    fclose(fp);
}

#endif /* readfile_h */
