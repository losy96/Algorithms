//
//  main.cpp
//  LinkedList
//
//  Created by 李浩 on 2017/1/21.
//  Copyright © 2017年 李浩. All rights reserved.
//

#include <iostream>
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //SingleLinkedList lihao(13,1,23,2,3,1,3,4,5,6,8,32,4,2);
    //lihao.displayList();
    
    
    int arr[] = {3,1,2,34,54,6,2,67,7,8,2,34,5,1,3,4,2,34,45,5,6,2,2,2,2,2,2,2,2,43,4,3,32,43,4,34,3,43,4,3,423,4};
//    SingleLinkedList lihao(sizeof(arr)/sizeof(int),arr);
//    lihao.displayList();
//    lihao.delAllSameElement(34);
//    lihao.displayList();
    
//    cout<<lihao.readElementNum()<<endl;
//    cout<<lihao.searchElementWithPlace(5).data<<endl;
//    lihao.delElement(2,5);
//    lihao.displayList();
//    cout<<lihao.readElementNum()<<endl;
    
    
    doubleLinkedList lihao(sizeof(arr)/sizeof(int),arr);
    //doubleLinkedList lihao(10,1,2,3,4,5,6,7,8,9,0);
    lihao.displayList();
    lihao.insertElement(4, 13);
    lihao.insertElement(11, 13);
    lihao.delElement(1);
    lihao.insertElement(45, 13);
    //lihao.displayList();
    //lihao.delElement(2);
    lihao.displayList();
    lihao.inverseDisplayList();
    
    

    return 0;
}

