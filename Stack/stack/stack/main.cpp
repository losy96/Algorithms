//
//  main.cpp
//  stack
//
//  Created by 李浩 on 2017/1/21.
//  Copyright © 2017年 李浩. All rights reserved.
//

#include <iostream>
#include "myStack.h"
using namespace std;
int main(int argc, const char * argv[]) {
    myStack lihao(10);
    lihao.push(1);
    lihao.push(3);
    lihao.push(4);
    lihao.push(32);
    lihao.push(12);
    lihao.push(2);
    lihao.push(4);
    lihao.push(1);
    for (int i = 0; i<8; i++) {
        cout<<lihao.pop()<<endl;
    }
    return 0;
}
