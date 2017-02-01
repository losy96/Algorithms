//
//  doubleLinkedList.h
//  LinkedList
//
//  Created by 李浩 on 2017/1/25.
//  Copyright © 2017年 李浩. All rights reserved.
//

#ifndef doubleLinkedList_h
#define doubleLinkedList_h
using namespace std;
class DoubleNode{
public:
    int data;
    DoubleNode *previous = NULL;
    DoubleNode *next = NULL;
};
class doubleLinkedList{
private:
    DoubleNode *head = new DoubleNode;
    DoubleNode *tail = new DoubleNode;
    int elementNum = 0;
public:
    doubleLinkedList(int num,int data,...);
    
    doubleLinkedList(int len,int *data);
    
    ~doubleLinkedList();
    
    DoubleNode * findElement(int place);
    
    bool insertElement(int place,int data);
    
    bool delElement(int place);
    
    void displayList();
    
    void inverseDisplayList();
};

doubleLinkedList::doubleLinkedList(int num,int data,...){
    head->next = tail;
    tail->previous = head;
    
    va_list arg_ptr;
    va_start(arg_ptr, data);
    for (int i = 1; i <= num; i++) {
        insertElement(i, data);
        data = va_arg(arg_ptr, int);
    }
    va_end(arg_ptr);
}

doubleLinkedList::doubleLinkedList(int len,int *data){
    head->next = tail;
    tail->previous = head;
    for (int i = len-1; 0<=i ; i--) {
        insertElement(1, data[i]);
    }
}

doubleLinkedList::~doubleLinkedList(){
    DoubleNode *temp = new DoubleNode;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    
}

DoubleNode * doubleLinkedList::findElement(int place){
    if (place > elementNum + 1 || place < 1) {
        cout<<"超出范围！当前共有节点数："<<elementNum<<endl;
        return NULL;
    }
    DoubleNode *temp = new DoubleNode;
    if (place <= elementNum/2) {
        temp = head;
        for (int i = 1; i <= place; i++) {
            temp = temp->next;
        }
    }
    else{
        temp = tail;
        for (int i = 1; i <= elementNum - place + 1; i++) {
            temp = temp->previous;
        }
    }
    return temp;
}

bool doubleLinkedList::insertElement(int place, int data){
    DoubleNode *temp = new DoubleNode;
    DoubleNode *insert = new DoubleNode;
    temp = findElement(place);
    if (temp == NULL) {
        return false;
    }
    insert->data = data;
    insert->next = temp;
    insert->previous = temp->previous;
    temp->previous->next = insert;
    temp->previous = insert;
    elementNum++;
    return true;
}

bool doubleLinkedList::delElement(int place){
    DoubleNode * temp = new DoubleNode;
    temp = findElement(place);
    if (temp == NULL) {
        return false;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;
    elementNum--;
    return true;
}

void doubleLinkedList::displayList(){
    DoubleNode *temp = new DoubleNode;
    temp = head;
    while (temp ->next->next != tail) {
        temp = temp -> next;
        cout<<temp->data<<",";
    }
    temp = temp -> next;
    cout<<temp->data<<endl;
}

void doubleLinkedList::inverseDisplayList(){
    DoubleNode *temp = new DoubleNode;
    temp = tail;
    while (temp->previous->previous != head) {
        temp = temp->previous;
        cout<<temp->data<<",";
    }
    temp = temp->previous;
    cout<<temp->data<<endl;
}
#endif /* doubleLinkedList_h */
