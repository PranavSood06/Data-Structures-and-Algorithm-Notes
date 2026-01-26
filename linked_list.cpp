#include<iostream>
#include<iomanip>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

// Single Linked list ---------------------------------------------------

/*
it stores two type of data 
1] data(val)
2] address of next value 
Visualisation :
  __100___    __200___      __300___
 |_data1_| -> |_data2_| -> |_data3_| 
 |_200___| -> |_300___| -> |_NULL__| 
    ^                          ^
    |                          |
   HEAD                       TAIL
*/

/*
->Firstly we will create a node class for storing that two types of data i.e. data and address of next value 
->we will make a constructor and pass the val we want in the ll and assign it to data and next to NULL
->in this way we got the nodes seperately and just have to join them now
        ______    
       |_data_|
       |_NULL_|
        ______
       |_data_|
       |_NULL_| ....
*/

class Node{
    public:
    // The two data types 
    int data;
    Node* next;

    // Storing val in Nodes 
    Node(int val){
        data = val;
        next = NULL;
    }
};

/*
-> We will make a list class to connect the nodes 
-> We will make two variables of Node data type head and tail for initial and last end of the ll
-> As the ll is empty so we will point both to NULL in the list constructor so that when we make a list osbj head and tail will automatically become NULL 
-> 
*/

class List{
    public:
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    // Node newNode(val);// Static
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail =newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"Linked list is empty";
            return ; 
        }
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val,int pos){
        if(pos<0)return;
        int count = 0;
        Node* newNode = new Node(val);
        Node* temp = head;
        if(pos==0){
            if(head==NULL){
                head = tail = newNode;
            }
            newNode->next=head;
            head = newNode;
            return;
        }
        while(count!=pos-1){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;        
        temp->next = newNode;
    }

    void printALL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

void LL_implementation(){
    List ll; 
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    //ll.pop_front();
    //ll.pop_back();
    ll.insert(78,0);
    ll. printALL();
    //ll.push_front(1);
    //cout<<endl;
    /*
    cout<<(ll.head->data);
    cout<<(ll.tail->data);
    */
}

// Doubly linked list ---------------------------------------------------
/*
      Structure of Node
        _________
       |_data___|  <- Data part
       |_ next_|  <- Address of next node
       |_ prev _|  <- Address of previous node

*/

class Dnode{
public :
    int data;
    Dnode* next;
    Dnode* prev;

    Dnode(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

};

class Doubly_list{
    Dnode* head;
    Dnode* tail;
public:
    Doubly_list(){
        head = tail = NULL;
    }
    void push_front(int val ){
        Dnode* newNode = new Dnode(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head ;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Dnode* newNode = new Dnode(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"Doubly linked list is empty";
            return ;
        }else{
            Dnode* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back(){
        if(tail == NULL){
            cout<<"Doubly linked list is empty";
            return ;
        }else{
            Dnode* temp = tail;
            tail = tail->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp;
        }
    }

    void show(){
        Dnode* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
    }
};


void DOubly_LL_implementation(){
    Doubly_list dl;
    dl.push_back(10);
    dl.push_back(20);
    dl.push_back(30);
    dl.show();
    cout<<endl;
    dl.pop_front();
    dl.show();
    cout<<endl;
    dl.pop_back();
    dl.show();
    return ;
}


// ---------- Middle of the link list ----------------------------
/*
To find the middle of the linked list we will use two pointer approach
it will help us to find the middle in one traversal only
We will make two pointers slow and fast both pointing to head initially
-> we will move slow by one step and fast by two steps in each iteration
-> when fast reaches the end , slow will be at the middle
Case 1 : ll has odd number of nodes
    1 -> 2 -> 3 -> 4 -> 5 -> NULL
         ^    ^
        slow fast
    
    1 -> 2 -> 3 -> 4 -> 5 -> NULL
              ^         ^
             slow      fast
    
    1 -> 2 -> 3 -> 4 -> 5 -> NULL
                     ^         ^
                    slow      fast(NULL)
    
    So , middle is 3
*/

Node* middle_of_ll(Node* head){
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


Node* flatten(Node* head) {
        //storing hed to curr
        Node* curr = head;
        //till the last node 
        while(curr!=NULL){
            //if the child is present
            if(curr->child != NULL){
                //Storing the next so it wont be lost
                Node* next = curr->next;
                //Setting curr's next to its child
                curr->next = flatten(curr->child);
                //It is a Dll
                curr->next->prev = curr;
                curr->child = NULL;
                //Moving the curr to the last node after flatting with the child
                while(curr->next!=NULL){
                    curr = curr->next;
                }
                // connect the next stored if present
                if(next!=NULL){
                    curr->next = next;
                    next ->prev = curr;
                }
            }
            // Traversing through the ll
            curr = curr->next;
        }
        //returning the head pointer
        return head;
    }
// Circular linked list ---------------------------------------------------

/*

*/

