#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<int> addOneToNumber(vector<int> arr)
{
    // Write your code here

    // the number will be 
    int n = arr.size();
    int number = 0,unit = 1;
    for(int i = n-1;i>=0;i--){
        number += arr[i] * unit ;
        unit *= 10;
    }
    number += 1;
    arr.clear();
    while(number != 0){
        int digit = number % 10;
        arr.push_back(digit);
        number /=10;
    }
    reverse(arr.begin(),arr.end());
    return arr;
}

bool isSafe(vector<vector<char>>& board,int row,int col, char dig){
        //if another digit already exist there
        if(board[row][col] != '.') return false;
        //Checking for entire row
        for(int i = 0;i<10;i++){
            if(board[row][i]==dig) return false;
        }
        //Checking for entire col
        for(int i = 0;i<10;i++){
            if(board[i][col]==dig) return false;
        }
        //Checking the grid 
        int stRow = (row/3)*3;
        int stcol = (col/3)*3;
        for(int i = stRow ; i<=stRow+2 ;i++){
            for(int j = stcol ; i<=stcol+2 ;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        
    }

    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int> even;
        for(int val:nums){
            if(val%2 == 0){
                even.push_back(val);
            }
        }
        int ans = 0;
        for(int val : even){
            ans = ans | val;
        }
        return ans;
    }

void merge(vector<int>& nums,int start,int mid,int end){
    int i = start,j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(nums[i]>=nums[j]){
            temp.push_back(nums[j++]);
        }else{
            temp.push_back(nums[i++]);
        }
    }
    while(i<=mid){
        temp.push_back(nums[i++]);
    }
    while(j<=end){
        temp.push_back(nums[j++]);
    }
    for(int k = 0;k<temp.size();k++){
        nums[k+start] = temp[k];
    }
}

void merge_sort(vector<int>& nums,int start,int end){
    if(start<end){
        int mid = start + (end-start)/2;
        merge_sort(nums,start,mid);
        merge_sort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    return ;
}

int triangleNumber(vector<int>& nums) {
    merge_sort(nums,0,nums.size()-1);
    return 0;
}

float area(vector<int> p1,vector<int> p2,vector<int> p3){
    return abs(p1[0]*(p2[1]-p3[1])+p2[0]*(p3[1]-p1[1])+p3[0]*(p1[1]-p2[1]))/2.0;
}

void stricly_increasing(vector<bool>& left,vector<int>& nums){
    left.push_back(true);
    for(int i = 1;i<nums.size();i++){
        if(nums[i-1]>=nums[i]) left.push_back(false);
        else left.push_back(true);
    }
}
void stricly_decresing(vector<bool>& right,vector<int>& nums){
    right.push_back(true);
    for(int i= nums.size()-2;i>=0;i--){
        if(nums[i]>nums[i+1]) right.push_back(true);
        else right.push_back(false);
    }
    reverse(right.begin(),right.end());
}

void prefixsum(vector<int>& leftsum,vector<int>& nums){
    leftsum.push_back(nums[0]);
    for(int i = 1;i<nums.size();i++){
        leftsum.push_back(leftsum[i-1]+nums[i]);
    }
}

void suffixsum(vector<int>& rightsum,vector<int>& nums){
    rightsum.push_back(nums[nums.size()-1]);
    for(int i = nums.size()-2;i>=0;i--){
        rightsum.push_back(rightsum[rightsum.size()-1]+nums[i]);
    }
    reverse(rightsum.begin(),rightsum.end());
}

void splitarray() {
    vector<int> nums = {3,1,2};
    vector<bool> left;
    vector<bool> right;
    stricly_increasing(left,nums);
    stricly_decresing(right,nums);
    vector<int> leftsum ;
    vector<int> rightsum;
    prefixsum(leftsum,nums);
    suffixsum(rightsum,nums);
    long long ans  = INT_MAX;
    for(int i = 0;i<nums.size()-1;i++){
        if(left[i]==true && right[i+1]==true){
            long long diff = abs(leftsum[i] - rightsum[i+1]);
            ans = min(ans,diff);
        }
    }
    if(ans == INT_MAX) ans = -1;
    cout<<ans<<endl;
    //return 0;
}

string k_balanced(int k){
    string left = "";
    string right = "";
    for(int i = 0;i<k;i++){
        left += "(";
        right += ")";
    }
    return left + right;
}


bool check_valid_pacific(vector<vector<int>>& heights,int n,int row,int col,int height,vector<vector<bool>>& visited){
    if(row>=n || col>=n || row<0 || col<0 || visited[row][col] == true) return false;

    if(height<heights[row][col]) return false;

    if(row == 0 || col == 0) {
        return true;
    }

    height = heights[row][col];
    visited[row][col] = true;

    bool found = check_valid_pacific(heights,n,row-1,col,height,visited)||
                 check_valid_pacific(heights,n,row,col-1,height,visited)||
                 check_valid_pacific(heights,n,row,col+1,height,visited)||
                 check_valid_pacific(heights,n,row+1,col,height,visited);
    visited[row][col] = false;
    return found ;
}

bool check_valid_Atlantic(vector<vector<int>>& heights,int n,int row,int col,int height,vector<vector<bool>>& visited){
    if(row>=n || col>=n || row<0 || col<0 || visited[row][col] == true) return false;

    if(height<heights[row][col]) return false;

    if(row == n-1 || col == n-1) {
        return true;
    }

    //height = heights[row][col];
    visited[row][col] = true;

    bool found = check_valid_Atlantic(heights,n,row-1,col,heights[row][col],visited)||
                 check_valid_Atlantic(heights,n,row,col-1,heights[row][col],visited)||
                 check_valid_Atlantic(heights,n,row,col+1,heights[row][col],visited)||
                 check_valid_Atlantic(heights,n,row+1,col,heights[row][col],visited);
    visited[row][col] = false;
    return found ;
}
/*
void check_valid_Atlantic(vector<vector<int>>& heights,int n,int row,int col,int height,vector<vector<bool>>& visited,vector<vector<int>>& result_A){
    if(row>=n || col>=n || row<0 || col<0 || visited[row][col] == true) return;

    if(heights[row][col]>height) return;

    if(row == n-1 || col == n-1) {
        result_A.push_back({row,col});
        return;
    }

    visited[row][col] = true;

    check_valid_Atlantic(heights,n,row-1,col,heights[row][col],visited,result_A);
    check_valid_Atlantic(heights,n,row,col-1,heights[row][col],visited,result_A);
    check_valid_Atlantic(heights,n,row,col+1,heights[row][col],visited,result_A);
    check_valid_Atlantic(heights,n,row+1,col,heights[row][col],visited,result_A);
    visited[row][col] = false;
    return ;
}
*/
//Fractional knapsack problem
void decsort(vector<int>& values, vector<int>& weight,vector<float>& ratio){
    for(int i = 0;i<values.size();i++){
        ratio.push_back(values[i]/weight[i]);
    }
    sort(ratio.begin(),ratio.end(),greater<int>());
}

vector<

int main(){
    vector<string> words;
    return 0;
}
