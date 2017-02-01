//
//  myStack.h
//  stack
//
//  Created by 李浩 on 2017/1/21.
//  Copyright © 2017年 李浩. All rights reserved.
//

#ifndef myStack__h
#define myStack__h
#include <iostream>
using namespace std;
class myStack{
private:
    int len = 0;
    int top = -1;
public:
    myStack(int len){
        this->len = len;
    }
    
    int *stack = new int[len];
    
    ~myStack(){
        delete[] stack;
    }
    
    bool isEmpty(){
        if (top == -1) {
            return true;
        }
        return false;
    }
    
    bool isFull(){
        if (top == len - 1){
            return true;
        }
        return false;
    }
    
    int pop(){
        if (isEmpty()) {
            cout<<"栈里面没元素了"<<endl;
            return 0;
        }
        top = top - 1;
        return stack[top + 1];
    }
    bool push(int temp){
        if (isFull()) {
            cout<<"栈满了"<<endl;
            return false;
        }
        top = top + 1;
        stack[top] = temp;
        return true;
    }
    
};


#endif /* myStack__h */
