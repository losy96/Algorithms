

#ifndef partialmatch_h
#define partialmatch_h
#include<iostream>
using namespace std;
//void partialArray(const char word[],int partialMatch[],int wordLength)
//{
//    int q,k;                                 //q: template string index; k: maximum prefix length
//    partialMatch[0] = 0;
//    for (q = 1,k = 0; q < wordLength; ++q)            
//    {
//        while(k > 0 && word[q] != word[k])
//            k = partialMatch[k-1];
//        if (word[q] == word[k])
//        {
//            k++;
//        }
//        partialMatch[q] = k;
//    }
//}



void partialArray(char *pattern,  int *next)
{
    int i = 0; //pattern
    int j = -1; //
    next[0] = -1;
    int pattern_len = strlen(pattern);
    while (i < pattern_len )
    {
        if (j ==-1 || pattern[i] == pattern[j])
            next[++i] =++j;
        else
            j = next[j];
    }
}




#endif /* partialmatch_h */