#include<iostream>
#include"QuickSort.h"
//using namespace std;
int main(){
	int A[10] = {22,31,43,34,44,47,58,25,40,54};
	QuickSort(A,0,9);
	for(int i = 0;i <= 9;i++){
		printf("%d\n",A[i]);
	}
	return 0;
}
