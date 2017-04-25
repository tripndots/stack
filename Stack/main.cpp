//
//  main.cpp
//  Stack
//
//  Created by Federico Dottin on 4/24/17.
//  Copyright © 2017 Federico Dottin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack{
public:
    Stack() {
        head = NULL;
    }
    void push(T data) {
        node* newNode = new node;
        newNode->data = data;
        if(head == NULL) {
            head = newNode;
            newNode->next = NULL;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void print() {
        itr = head;
        while (itr != NULL) {
            cout << itr->data << endl;
            itr = itr->next;
        }
    }
    T pop() {
        if(head == NULL)
            throw "Cannot Pop when the stack is empty";
        T ret = head->data;
        node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
        return ret;
    }
private:
    struct node {
        node* next;
        T data;
    };
    node* head;
    node* itr;
};

int main(int argc, const char * argv[]) {
    Stack<int> myStack;
    
    myStack.push(15);
    myStack.push(30);
    myStack.push(378);
    myStack.push(23);
    cout << myStack.pop() << " has been popped" << endl;
    myStack.print();
    
    return 0;
}
