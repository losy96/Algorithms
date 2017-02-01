#ifndef QuickSort_h
#define QuickSort_h
#include<iostream>
using namespace std;
class QuickSort{
	public: static int Partition(int * A,int p,int r){
		int x = A[r];
		printf("x:%d",A[r]);
		int i = p - 1;
		int temp = 0;

		for (int j = p;j<r;j++){
			if (A[j] <= x){
				i = i + 1;
				printf("i:%d ",i);
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		temp = A[i+1];
		A[i+1] = A[r];
		A[r] = temp;
		return i+1;
	}
	QuickSort(int * A,int p,int r){
		if (p < r){
			int q = Partition(A,p,r);
			for(int a = 0;a<=9;a++){
				printf("%d ",A[a]);
			}
			printf("\n");
			QuickSort(A,p,q - 1);
			QuickSort(A,q + 1,r);
		}
	}
};
#endif
