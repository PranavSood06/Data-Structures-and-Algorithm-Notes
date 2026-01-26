#include<bits/stdc++.h>
using namespace std;


// Using vector to implement stack
class Stack{
    vector<int> arr;
    public:
    void push(int x){
        arr.push_back(x);
    }
    void pop(){
        if(!arr.empty()){
            arr.pop_back();
        }else{
            cout<<"Stack underflow"<<endl;
        }
    }
    int top(){
        if(!arr.empty()){
            return arr.back();
        }else{
            cout<<"Stack is empty"<<endl;
        }
        return -1;
    }
    bool empty(){
        return arr.size()==0;
    }
};

// Using Linked list to implement stack
class Stack_list{
    list<int> arr;
    public:
    void push(int x){
        arr.push_front(x);
    }
    void pop(){
        if(!arr.empty()){
            arr.pop_front();
        }else{
            cout<<"Stack underflow"<<endl;
        }
    }
    int top(){
        if(!arr.empty()){
            return arr.front();
        }else{
            cout<<"Stack is empty"<<endl;
        }
        return -1;
    }
    bool empty(){
        return arr.size()==0;
    }
};

int main(){
    Stack_list s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    cout<<"Poped from stack"<<endl;
    cout<<"Top element is "<<s.top()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }// 30 20 10 
    return 0;
}