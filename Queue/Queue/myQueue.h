//
//  myQueue.h
//  Queue
//
//  Created by 李浩 on 2017/1/21.
//  Copyright © 2017年 李浩. All rights reserved.
//

#ifndef myQueue_h
#define myQueue_h
#include<iostream>
using namespace std;
class myQueue{
private:
    int head = 0;
    int tail = 0;
    int len = 0;
public:
    myQueue(int len){
        this->len = len + 1;
    }
    
    int *queue = new int[len];
    
    ~myQueue(){
        delete[] queue;
    }
    
    bool isEmpty(){
        //cout<<tail<<"tail"<<endl;
        //cout<<head<<"head"<<endl;
        if (head == tail)
        {
            return true;
        }
        return false;
    }
    
    bool isFull(){
        //cout<<tail<<"tail"<<endl;
        //cout<<head<<"head"<<endl;
        if (head == (tail + 1) % len) {
            return true;
        }
        return false;
    }
    
    bool enQueue(int temp){
        if (isFull()) {
            cout<<"队列满了"<<endl;
            return false;
        }
        //cout<<tail<<"qw"<<endl;
        queue[tail] = temp;
        tail = tail + 1;
        tail = tail % len;
        return true;
    }
    
    int deQueue(){
        if(isEmpty()){
            cout<<"队列空的"<<endl;
            return 0;
        }
        int temp = queue[head];
        head++;
        head = head % len;
        return temp;
    }
  
    
};
#endif /* myQueue_h */
