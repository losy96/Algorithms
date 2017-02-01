//
//  singleLinkedList.h
//  LinkedList
//
//  Created by 李浩 on 2017/1/21.
//  Copyright © 2017年 李浩. All rights reserved.
//

#ifndef singleLinkedList_h
#define singleLinkedList_h
#include <iostream>
using namespace std;

class Node{
public:
    Node *next = NULL;
    int data;
};

class SingleLinkedList{
private:
    Node *head = new Node;
    int elementNum = 0;
public:
    SingleLinkedList(int num,int data,...);
    
    SingleLinkedList(int len,int *data);
    
    ~SingleLinkedList();
    
    bool insertList(int place ,int data);
    
    bool delElement(int place);
    
    bool delElement(int start,int end);
    
    bool delAllSameElement(int data);
    
    SingleLinkedList searchElementWithData(int data);
    
    Node searchElementWithPlace(int place);
    
    void displayList();
    
    int readElementNum();
};

SingleLinkedList::SingleLinkedList(int num,int data,...){
    head->data = 0;
    head->next = NULL;
    Node *temp = new Node;
    temp = head;
    
    va_list arg_ptr;
    va_start(arg_ptr, data);
    for (int i = 1; i <= num; i++) {
        insertList(i, data);
        data = va_arg(arg_ptr, int);
    }
    va_end(arg_ptr);
    
}

SingleLinkedList::SingleLinkedList(int len,int *data){
    for (int i = 1; i <= len; i++) {
        insertList(i, data[i-1]);
    }
}

SingleLinkedList::~SingleLinkedList(){
    Node *temp = new Node;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
}

bool SingleLinkedList::delElement(int place){
    Node *temp = new Node;
    Node *del = new Node;
    temp = head;
    for (int i = 1; i < place; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            cout<<"删除元素不存在"<<endl;
            return false;
        }
    }
    del = temp->next;
    temp->next = del->next;
    delete del;
    elementNum--;
    return true;
}

bool SingleLinkedList::delElement(int start, int end){
    int place = start;
    while (start <= end) {
        if (delElement(place)) {
            start++;
        }
        else{
            cout<<"删除越界"<<endl;
            return false;
        }
    }
    return true;
}

bool SingleLinkedList::insertList(int place, int data){
    Node *temp = new Node;
    temp = head;
    Node *insert = new Node;
    insert->data = data;
    for (int i = 1; i < place; i++) {
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;
    elementNum++;
    return true;
}

bool SingleLinkedList::delAllSameElement(int data){
    Node *temp = new Node;
    temp = head;
    int place = 1;
    while (temp->next) {
        temp = temp->next;
        if (temp->data == data) {
            delElement(place);
        }
        else{
            place++;
        }
    }
    return true;
}

SingleLinkedList SingleLinkedList::searchElementWithData(int data){
    Node *temp = new Node;
    temp = head;
    int place = 0;
    int hashPlace = 0;
    SingleLinkedList hash(0,0);
    while (temp->next) {
        temp = temp->next;
        place++;
        if (temp->data == data) {
            hashPlace++;
            hash.insertList(hashPlace, place);
        }
    }
    return hash;
}


Node SingleLinkedList::searchElementWithPlace(int place){
    Node *temp = new Node;
    temp = head;
    for (int i = 1; i <= place; i++) {
        temp = temp->next;
    }
    return *temp;
}



void SingleLinkedList::displayList(){
    Node *temp = new Node;
    temp = head->next;
    while(temp->next) {
        cout<<temp->data<<",";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int SingleLinkedList::readElementNum(){
    return elementNum;
}

#endif /* singleLinkedList_h */
