

#ifndef inputwordlength_h
#define inputwordlength_h
#include<iostream>
#include <stdio.h>
using namespace std;
int inPutWordLength(){
    int wordLength;
    cout<<"Please enter the word length:";
    cin>>wordLength;
    return wordLength;
}
void inPutWord(char *word){
    cout<<"Please enter the word:";
    cin>>word;
}

#endif /* inputwordlength_h */
