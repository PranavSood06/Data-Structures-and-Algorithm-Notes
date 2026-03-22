#include <bits/stdc++.h>
using namespace std;

// Queue ---------------------------------------------------
/*
-> Queue is a linear data structure which follows the principle of FIFO (First In First Out)
-> It has two main operations
    1] Enqueue : It is the operation of adding an element to the rear of the queue
    2] Dequeue : It is the operation of removing an element from the front of the queue
*/

class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Queue{
public:
    Node* head;
    Node* rear;
    
    Queue(){
        head = NULL;
        rear = NULL;
    }

    void enqueue(int x){
        Node* newNode = new Node(x);
        if(isEmpty()){
            head = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(isEmpty()){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(isEmpty()){
            return NULL;
        }
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};


int main(){  
    Queue q;
    /*
    using stl 
    queue<int> q;    
    */
    q.enqueue(15);
    q.enqueue(14);
    q.enqueue(13);
    q.enqueue(12);
    q.enqueue(11);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }
    return 0;
}


