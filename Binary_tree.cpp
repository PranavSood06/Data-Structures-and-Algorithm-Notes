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
    return 0;
}