#include<bits/stdc++.h>
using namespace std;

/*
 ------ BINARY TREES ----------
 A Binary Tree is a tree data structure in which each node has at most two
 children, called left child and right child.

 -> COMPONENTS 
 ---->NODE : Basic unit of a tree
            Contains:
                Data (value)
                Left pointer
                Right pointer
 -> ROOT
 ----> The topmost node of the tree
        Starting point
 -> PARENT NODE
 ----> A node that has children
 -> Leaf Node
 ----> Node with no children
 -> Internal Node
 ----> Node with at least one child
 -> Edge
 =---> Connection between two nodes
*/
//Making a Binary tree
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* MakeBinaryTree(vector<int> &nums){
    idx++;
    if(nums[idx] == -1) return NULL;
    Node* root = new Node(nums[idx]);
    root->left = MakeBinaryTree(nums);
    root->right = MakeBinaryTree(nums);
    return root;
}

// root -> left -> left -> NULL -> backtrack -> right
void preordertraversal(vector<int> &traversal,Node* root){
    if(root == NULL) return ;
    traversal.push_back(root->data);
    preordertraversal(traversal,root->left);
    preordertraversal(traversal,root->right);
}

/*Visit nodes in the order:
👉 Left → Right → Node
*/
void postordertraversal(vector<int> &traversal,Node* root){
    if(root == NULL) return ;
    preordertraversal(traversal,root->left);
    preordertraversal(traversal,root->right);
    traversal.push_back(root->data);
}
/*
📌 Definition:
Visit nodes in the order:
👉 Left → Node → Right
*/
void inordertraversal(vector<int> &traversal,Node* root){
    if(root == NULL) return ;
    preordertraversal(traversal,root->left);
    traversal.push_back(root->data);
    preordertraversal(traversal,root->right);
}
/*
Height = how many edges from a node down to the deepest leaf below it. A leaf node has height 0.
*/
//Height of a tree
int height_of_a_tree(Node* root){
    if(root == NULL) return 0;
    int left = height_of_a_tree(root->left);
    int right = height_of_a_tree(root->right);
    return  max(left,right)+1;
}

//Number of nodes
int countNodes(Node* root){
    if(root == NULL) return 0;
    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);
    return  leftcount + rightcount+1;
}

//Sum of Nodes
int sumNodes(Node* root){
    if(root == NULL) return 0;
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    return leftSum+rightSum+root->data;
}


/*Diameter is the length of the longest path between any two nodes
*/
int diameter(Node* root){
     return -1;
}

// Top view of binary tree
void top_view(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    mp[0] = root->data;
    while(!q.empty()){
        Node* curr = q.front().first;
        int HD = q.front().second;
        q.pop();
        if(mp.find(HD) == mp.end()){
            mp[HD] = curr->data;
        }
        if(curr->left!= NULL){
            q.push({curr->left,HD-1});
        }
        if(curr->right!= NULL){
            q.push({curr->right,HD+1});
        }
    }
    for(auto it:mp){
        cout<<it.second<<" ";
    }
}

//kth level of the binary tree 
void kthLevel(Node* root,int k){
    if(!root) return ;
    if(k == 1){
        cout<<root->data<<" ";
        return ;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);
    return ;
}

//Lowest Common Ancester
Node* LCF(Node* root,Node* p,Node* q){
    if(root==NULL) return NULL;
    if(root->data==p->data || root->data == q->data) return root;
    Node* left = LCF(root->left,p,q);
    Node* right = LCF(root->right,p,q);
    if(left && right) return root;
    if(left) return left ;
    return right;
}

//Sum tree
int sumtree(Node* root){
    if(root == NULL) return 0;
    int left = sumtree(root->left);
    int right = sumtree(root->right);
    root->data += left + right;
    return root->data;
}

//Morris Inorder Trversal
//node previous of a node in inorder traversal is called its predesssor
Node* InorderPredecessor(Node* curr){
    Node* org = curr;
    curr = curr -> left;
    while(curr->right!=NULL && curr->right != org){
        curr->right;
    }
    return curr;
}
//Its take O(n) times but O(1) space thats the magic of the morris inorder traversal 
vector<int> MIT(Node* root,vector<int> ans){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* IP = InorderPredecessor(curr);
            if(IP->right == NULL){
                IP-> right = curr;
                curr = curr->left;
            }else{
                IP -> right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

/*
CBT indexing
*/

//Flatten a BinaryTree to a linked list 
Node* Nextright = NULL;
void flatten(Node* root) {
    if(root == NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->left = NULL;
    root->right = Nextright;
    Nextright = root;
}


//Binry search tree
// 🌳 Binary Search Tree (BST)
// A Binary Tree where for every node:
// - All values in the left subtree are smaller than the node
// - All values in the right subtree are greater than the node
// - This property holds recursively for every node

// ➕ Insertion in BST:
// 1. Start from the root
// 2. Compare the value to be inserted with current node:
//    - If value < node->val → move to left subtree
//    - If value > node->val → move to right subtree
// 3. Repeat until you reach a NULL position
// 4. Insert the new node at that position

// ⏱ Time Complexity:
// - Average: O(log n)
// - Worst case (skewed tree): O(n)

// 🧠 Key Idea:
// BST follows: Left < Root < Right

//Insert a Node
Node* insert(Node* root,int val){
    if(root==NULL) return new Node(val);
    if(root->data > val){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

//Search in a Tree
bool ispresent(Node* root,int target){
    if(root==NULL) return false;
    if(root->data == target) return true;
    return root->data>target?ispresent(root->left,target):ispresent(root->right,target);
}
//Delete a Node
Node* InorderSuccessor(Node* curr){
    curr = curr->right;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Node* deleteNode(Node* root, int key) {
    if(root==NULL) return NULL;
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root ;
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root ;
            return temp;
        }
        Node* IS = InorderSuccessor(root);
        root->data = IS->data;
        root->right  = deleteNode(root->right,IS->data);
        return root;
    }
    return root;
}


int main(){
    vector<int> nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = MakeBinaryTree(nums);
    cout<<"Height : "<<height_of_a_tree(root)<<endl;
    cout<<"Nodes : "<<countNodes(root)<<endl;
    cout<<"Sum : "<<sumNodes(root)<<endl;
    cout<<"Top view of a Binary Tree"<<endl;
    top_view(root);
    cout<<endl;
    cout<<"Kth level of a binary tree : ";
    int k = 2;
    kthLevel(root,k);
    cout<<endl;
    Node* p = new Node(4);
    Node* q = new Node(5);
    Node* LCF_ = LCF(root,p,q);
    cout<<"LCF when p = 4 , q = 5 : "<<LCF_->data<<endl;
    cout<<"Sum Tree : "<<endl;
    cout<<sumtree(root);
    return 0;
}