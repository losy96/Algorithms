//
//  main.cpp
//  Queue
//
//  Created by 李浩 on 2017/1/21.
//  Copyright © 2017年 李浩. All rights reserved.
//

#include <iostream>
#include "myQueue.h"
using namespace std;
int main(int argc, const char * argv[]) {
    myQueue lihao(10);
    lihao.enQueue(2);
    lihao.enQueue(3);
    lihao.enQueue(4);
    lihao.enQueue(5);
    lihao.enQueue(6);
    lihao.enQueue(7);
    lihao.enQueue(8);
    lihao.enQueue(9);
    cout<<lihao.deQueue()<<endl;
    lihao.enQueue(0);
    lihao.enQueue(1);
    cout<<lihao.deQueue()<<endl;
    lihao.enQueue(2);
    lihao.enQueue(3);
    cout<<lihao.deQueue()<<endl;
    cout<<lihao.deQueue()<<endl;
    cout<<lihao.deQueue()<<endl;
    lihao.enQueue(4);
    lihao.enQueue(5);
    cout<<lihao.deQueue()<<endl;
    cout<<lihao.deQueue()<<endl;
    cout<<lihao.deQueue()<<endl;
    lihao.enQueue(6);
    lihao.enQueue(7);
    lihao.enQueue(8);
    lihao.enQueue(9);
    for (int i = 0; i < 10; i++) {
        cout<<lihao.deQueue()<<endl;
    }
    return 0;
}
