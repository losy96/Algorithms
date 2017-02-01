//
//  Tree.h
//  Tree
//
//  Created by 李浩 on 2017/1/29.
//  Copyright © 2017年 李浩. All rights reserved.
//

#ifndef Tree_h
#define Tree_h
#include<iostream>
using namespace std;
class Node{
public:
    int key;
    int keyNum = 1;
    Node *left = NULL;
    Node *right = NULL;
    Node *pre = NULL;
};

class Tree{
private:
    Node *head = new Node;
public:
    Tree(int num,int data,...);
    
    Tree(int len,int *data);
    
    ~Tree();
    
    void delAllElement(Node *temp);
    
    bool insertElement(int data);
    
    void display(Node *temp);
    
    void orderDisplay(Node *temp);
    
    bool delElement(int key);
    
    bool delTree(int key);
    
    Node *findElement(Node *temp,int key);
    
    Node* getHead();
    
};

Tree::Tree(int num,int data,...){
    head->key = data;
    va_list arg_ptr;
    va_start(arg_ptr, data);
    for (int i = 1; i < num; i++) {
        data = va_arg(arg_ptr, int);
        insertElement(data);
    }
    va_end(arg_ptr);
}

Tree::Tree(int len,int *data){
    head->key = data[0];
    for (int i = 1; i < len; i++) {
        insertElement(data[i]);
    }
}

Tree::~Tree(){
    delAllElement(head);
}

void Tree::delAllElement(Node *temp){
    if (temp != NULL) {
        if (temp->left) {
            delAllElement(temp->left);
        }
        if (temp->right) {
            delAllElement(temp->right);
        }
        delete temp;
        temp = NULL;
    }
}

bool Tree::delTree(int key){
    Node *tempHead = new Node;
    tempHead = findElement(head, key);
    if (tempHead == NULL) {
        cout<<"删除失败"<<endl;
        return false;
    }
    if (tempHead == head) {
        delAllElement(head);
        head = NULL;
        return true;
    }
    else{
        if (tempHead->pre->left == tempHead) {
            tempHead->pre->left = NULL;
            delAllElement(tempHead);
            tempHead = NULL;
            return false;
        }
        else{
            tempHead->pre->right = NULL;
            delAllElement(tempHead);
            tempHead = NULL;
            return true;
        }
    }
    return true;
}

bool Tree::insertElement(int data){
    Node *temp = new Node;
    temp = head;
    Node *insert = new Node;
    insert->key = data;
    while (1) {
        if (data < temp->key) {
            if (temp->left != NULL) {
                temp = temp->left;
            }
            else{
                temp->left = insert;
                insert->pre = temp;
                break;
            }
        }
        if (data > temp->key){
            if (temp->right != NULL) {
                temp = temp->right;
            }
            else{
                temp->right = insert;
                insert->pre = temp;
                break;
            }
        }
        if (data == temp->key) {
            temp->keyNum++;
            break;
        }
    }
    return true;
}

void Tree::display(Node *temp){
    if (temp) {
        if (temp->left != NULL) {
            display(temp->left);
        }
        if (temp->right != NULL) {
            display(temp->right);
        }
        cout<<temp->key;
        if (temp->keyNum != 1) {
            cout<<"("<<temp->keyNum<<")"<<",";
        }
        else{
            cout<<",";
        }

    }
}

void Tree::orderDisplay(Node *temp){
    if (temp) {
        if (temp->left != NULL) {
            orderDisplay(temp->left);
        }
        cout<<temp->key;
        if (temp->keyNum != 1) {
            cout<<"("<<temp->keyNum<<")"<<",";
        }
        else{
            cout<<",";
        }
        if (temp->right != NULL) {
            orderDisplay(temp->right);
        }
    }
}

bool Tree::delElement(int key){
    Node *temp = new Node;
    temp = findElement(head, key);
    if (temp == NULL) {
        cout<<"元素不存在，删除失败"<<endl;
        return false;
    }
    if (temp->left == NULL && temp->right == NULL ) {
        if (temp == head) {
            cout<<"head";
            delete temp;
            temp = NULL;
            head = NULL;
            return true;
        }
        cout<<"单独的"<<endl;
        if (temp->pre->left == temp) {
            temp->pre->left = NULL;
        }
        else{
            temp->pre->right = NULL;
        }
        delete temp;
        temp = NULL;
        return true;
    }
    if (temp->left == NULL || temp->right == NULL) {
        Node *headPre = new Node;
        if (temp == head) {
            cout<<"head";
            temp->pre = headPre;
            headPre->right = temp;
        }
        cout<<"有一个"<<endl;
        Node *tempPre = new Node;
        tempPre = temp->pre;
        Node *tempNext = new Node;
        if (temp->left == NULL) {
            tempNext = temp->right;
        }
        else{
            tempNext = temp->left;
        }
        if (tempPre->left == temp) {
            tempPre->left = tempNext;
            tempNext->pre = tempPre;
            if (temp == head) {
                head = tempNext;
                head->pre = NULL;
                headPre = NULL;
                delete tempPre;
                tempPre = NULL;
            }
            delete temp;
            return true;
        }
        else{
            tempPre->right = tempNext;
            tempNext->pre = tempPre;
            if (temp == head) {
                head = tempNext;
                head->pre = NULL;
                headPre = NULL;
                delete tempPre;
                tempPre = NULL;
            }
            delete temp;
            temp = NULL;
            return true;
        }
    }
    if (temp->left != NULL && temp->right != NULL) {
        cout<<"有两个"<<endl;
        Node *headPre = new Node;
        if (temp == head) {
            cout<<"head";
            headPre->right = temp;
            temp->pre = headPre;
        }
        if (!temp->right->left) {
            Node *tempPre = new Node;
            tempPre = temp->pre;
            Node *tempRight = new Node;
            tempRight = temp->right;
            tempRight->left = temp->left;
            tempRight->pre = temp->pre;
            temp->left->pre = tempRight;
            if (temp->pre->left == temp) {
                temp->pre->left = tempRight;
            }
            else{
                temp->pre->right = tempRight;
            }
            if (head == temp) {
                head = tempRight;
                head->pre = NULL;
                delete tempPre;
                tempPre = NULL;
                headPre = NULL;
            }
            delete temp;
            temp = NULL;
            return true;
        }
        else{
            Node *replaceTemp = new Node;
            replaceTemp = temp->right;
            while (replaceTemp->left) {
                replaceTemp = replaceTemp->left;
            }
            cout<<"replce:"<<replaceTemp->key<<endl;
            if (replaceTemp->right) {
                Node *rReplaceTemp = new Node;
                rReplaceTemp = replaceTemp->right;
                rReplaceTemp->pre = replaceTemp->pre;
                replaceTemp->pre->left = rReplaceTemp;
            }
            else{
                replaceTemp->pre->left = NULL;
            }
            replaceTemp->left = temp->left;
            replaceTemp->right = temp->right;
            replaceTemp->pre = temp->pre;
            temp->pre->right = replaceTemp;
            temp->right->pre = replaceTemp;
            temp->left->pre = replaceTemp;
            if (head == temp) {
                head = replaceTemp;
                head->pre = NULL;
                delete headPre;
                headPre = NULL;
            }
            delete temp;
            temp = NULL;
            return true;
            
        }
    }
    return true;
}

Node *Tree::findElement(Node *temp,int key){
    if (temp) {
        if (key < temp->key) {
//            cout<<"left";
            if (temp->left != NULL) {
                temp = temp->left;
                temp = findElement(temp, key);
            }
            else{
                cout<<"NULL";
                return NULL;
            }
        }
    }
    if (temp) {
        if (key > temp->key) {
//            cout<<"right";
            if (temp->right != NULL) {
                temp = temp->right;
                temp = findElement(temp, key);
            }
            else{
                cout<<"NULL";
                return NULL;
            }
        }
    }
    return temp;
}

Node *Tree::getHead(){
    return head;
}


#endif /* Tree_h */
