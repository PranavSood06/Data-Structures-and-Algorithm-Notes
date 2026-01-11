#include<iostream>
#include<vector>
using namespace std;
# define MAX 1000

class stack{
    int top;
public:
    //Maximum size of stack 
    int a[MAX];

    stack(){
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();

};

bool stack::push(int x){
    if(top>=(MAX-1)){
        std::cout<<"Stack Overflow";
        return false;
    }else{
        a[++top]=x;
        std::cout<<x<<" Pushed into Stack"<<std::endl;
        return true;
    }
}

int stack::pop(){
    if(top<0){
        std::cout<<"Stack Underflow"<<std::endl;
        return 0;
    }else{
        int x = a[top--];
        return x;
    }
}

int stack::peek(){
    if(top<0){
        std::cout<<"Stack is Empty"<<std::endl;
        return 0;
    }else{
        int x = a[top];
        return x;
    }
}

bool stack::isEmpty(){
    return top<0;
}

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<"Poped from stack"<<endl;
    cout<<"Top element is "<<s.peek()<<endl;
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }// 30 20 10 
    return 0;
}