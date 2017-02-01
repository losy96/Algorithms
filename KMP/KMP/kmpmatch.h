#ifndef KMPmatch_h
#define KMPmatch_h
#include<iostream>
using namespace std;
int kmpMatch(char * article,char * word,int articleLength,int wordLength,int *partialMatchArray){
    int k = 0;
    int num=0;
    int lineNum = 1;
    for(int i = 0;i<articleLength;i++){
        //        cout<<"1 ";
        if (article[i] == '\n') {
        lineNum++;
    }
        while (k > 0 && article[i] != word[k]) {
//            cout<<partialMatchArray[k]<<" ";
//              cout<<"2 ";
             k = partialMatchArray[k];
        }
        if (article[i] == word[k]) {
//              cout<<"3 ";
//            cout<<"k:"<<k<<" ";
            k++;
        }
        if (k == wordLength) {
//            cout<<"4 ";
            cout<<"place:"<<i + 2 - wordLength<<"-"<<i+1<<" ";
            cout<<"lineNum:"<<lineNum<<endl;
            num++;
        }
        
    }
    cout<<"Num:"<<num<<endl;
       return 0;
}



#endif /* KMPmatch_h */
