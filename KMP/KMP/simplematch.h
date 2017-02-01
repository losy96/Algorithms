
#ifndef simplematch_h
#define simplematch_h
#include<iostream>
using namespace std;
int simpleMatch(char * article,char * word,int articleLength,int wordLength){
    int i = 0;
    int num = 0;
    int lineNum = 1;
    //int j = 0;
    while(i<=articleLength - wordLength){
        //cout<<"1";
        i++;
        if (article[i-1] == '\n') {
            lineNum++;
        }
        if(article[i-1] == word[0])
        {
            for(int k = 1;k<=wordLength;)
            {
                if (article[i-1+k] == '\n') {
                    lineNum++;
                }
                //cout<<"2";
                if(article[i-1+k] == word[k])
                {
                    //cout<<"3";
                    k++;
                    //	cout<<"k:"<<k<<" ";
                    if(k == wordLength)
                    {
//                        cout<<"i:"<<i<<endl;
                        cout<<"place:"<<i<<"－"<<i+wordLength-1<<" ";
                        cout<<"lineNum:"<<lineNum<<endl;
//                        cout<<"i:"<<i<<endl;
//                        i = i + wordLength;
                        num++;
                        i = i+wordLength-1;
//                        cout<<num<<endl;
                        //continue;
                        break;
                    }
                }
                else
                {
                    break;
                    //continue;
                }
            }
        }
    }
    cout<<"Num:"<<num<<endl;
    return 0;
}

#endif /* simplematch_h */
