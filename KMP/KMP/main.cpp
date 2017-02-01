#include<iostream>
#include"readfile.h"
#include"inputwordlength.h"
#include"simplematch.h"
#include"partialmatch.h"
#include "kmpmatch.h"
#include<time.h>
#include "creatfile.h"
using namespace std;
char *article;
char *word;
int *partialMatchArray;   //partial match array
int ArticleLength;
int wordLength;
int readArticleFromFile(){           //Ω´Œƒº˛÷–µƒ◊÷∑˚¥Æ¥Ê∑≈÷¡ ˝◊Èarticle÷–
    ArticleLength = articleLong();
    cout<<ArticleLength<<endl;
    article = new char[ArticleLength];   //¥Ê∑≈Œƒº˛÷–◊÷∑˚¥Æ
    readFile(article);
    cout<<article;
    cout<<endl;
    return 0;
}
int getWord(){
    wordLength = inPutWordLength();
    word = new char[wordLength];      //¥Ê∑≈–Ë≤È’“µƒ◊÷∑˚¥Æ
    inPutWord(word);
    cout<<word<<endl;
    return 0;
}
int KMP(){             //KMP function
    partialMatchArray = new int(wordLength);
    partialArray(word, partialMatchArray);    //obtain partial match array
    kmpMatch(article, word, ArticleLength, wordLength,partialMatchArray);

    return 0;
}
void choose(){
    int n = 0;
    cout<<"String Matching"<<endl;
    cout<<"1.Create a file"<<endl<<"2.Simple matching"<<endl<<"3.KMP matching"<<endl<<"4.Exit";
    cin>>n;
    clock_t start_time;
    clock_t end_time;
    switch (n) {
        case 1:
            creatFile();
            choose();
            break;
        case 2:
            readArticleFromFile();
            getWord();
            start_time = clock();
            simpleMatch(article,word,ArticleLength,wordLength);   //simple match function
            end_time = clock();
            cout<<"time:"<<end_time - start_time<<endl;
           
            choose();
            break;
        case 3:
            readArticleFromFile();
            getWord();
            start_time = clock();
            KMP();
            end_time = clock();
            cout<<"time:"<<end_time - start_time<<endl;
//          cout<<"haha";
            for (int i=0; i<wordLength; i++) {
                cout<<partialMatchArray[i]<<" ";
            }
            choose();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Please select again:";
            choose();
            break;
    }
}
int main(){
    choose();
        return 0;
}
