//
//  main.cpp
//  Tree
//
//  Created by 李浩 on 2017/1/29.
//  Copyright © 2017年 李浩. All rights reserved.
//

#include <iostream>
#include "Tree.h"
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[] = {3,2,4,7,5,76,12,78,10,13,8,11,21,1,12,2,2,3,4,5,34,567,9};
    Tree lihao(sizeof(arr)/sizeof(int),arr);
    lihao.display(lihao.getHead());
    cout<<endl;
//    for (int i = 0; i<sizeof(arr)/sizeof(int)-6; i++) {
//        lihao.delElement(arr[i]);
//        lihao.display(lihao.getHead());
//        cout<<"删除："<<arr[i]<<" ";
//    }
    lihao.delTree(100);
   lihao.orderDisplay(lihao.getHead());
    return 0;
}
