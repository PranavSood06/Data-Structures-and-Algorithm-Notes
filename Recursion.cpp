#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// All problems solved by loops can be done by recursion and vice versa
/*
Call stack

*/
void number(int n)
{
    if (n == 1)
    {
        cout << n;
        return;
    }
    cout << n << " ";
    number(n - 1);
}
/*
Recurrence relation :
It is used to find the time complexity
<<<
    The main thing our above function is doing is  print n and applying same func on n-1
    so by reccurence relation :
f(n) = print"n" + f(n-1)
TC(n) = O(1) + TC(n-1)
*/

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

/*
Time complexity can be founded by 2 methods here :
    1) Recurrence Relation
    2)TC = Total no. of      +   work done in
           recursion calls        each call

By Recurrence relation  <<Method 1>>
f(n) = K + f(n-1)
f(n-1) = K + f(n-2)
f(n-2) = K + f(n-3)
f(n-3) = K + f(n-4)
.
.
f(1) = K + f(0)

by adding all the above equations we get,
f(n) = K*n + f(0)(K2)
we will ignore the cosntants
TC = O(n)

<<Method 2>>
count the number of recursion calls nd multiply it by work done in one call
total no. of calls : n
TC in one call : K
TC total  : n*K
*/

/*
Space complexity
SC = Height of call stack + Memory in each call
*/

// sum of n numbers

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

// Fibonachi series
int fib(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Check if the array is sorted
bool isSorted(vector<int> nums, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    return nums[n - 1] >= nums[n - 2] && isSorted(nums, n - 1);
}

// Binary Search
bool BSearch(vector<int> &nums, int tar, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == tar)
        {
            return true;
        }
        else if (nums[mid] >= tar)
        {
            return BSearch(nums, tar, start, mid - 1);
        }
        else
        {
            return BSearch(nums, tar, mid + 1, end);
        }
    }
    return false;
}

void subsets(vector<int> &nums, vector<int> &ans, int i)
{
    if (i == nums.size())
    {
        for (int val : ans)
        {
            cout << val << " ";
        }

        cout << "i : " << i << endl;
        return;
    }
    // include
    ans.push_back(nums[i]);
    subsets(nums, ans, i + 1);
    // exclude
    ans.pop_back();
    subsets(nums, ans, i + 1);
}

// Print n terms using recursion
void nTerms(int n, int i)
{
    if (i == n)
    {
        cout << i << " " << endl;
        return;
    }
    cout << i << " ";
    nTerms(n, i + 1);
}

// printing 1 to N using backtrakking
void nTerms_(int n, int i)
{
    if (i < 1)
    {
        return;
    }
    nTerms_(n, i - 1);
    cout << i << " ";
}

// Permutation in string
void permute(vector<string> &str, int idx)
{
    if (idx == str.size())
    {
        for (string c : str)
        {
            cout << c;
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < str.size(); i++)
    {
        swap(str[idx], str[i]);
        permute(str, idx + 1);
        swap(str[idx], str[i]);
    }
}

// Recursion and backtrakking

// Rat in a maze
/*

*    0 1 2 3
0  [ 1 0 0 0 ]
1  [ 1 1 0 1 ]
2  [ 1 1 0 0 ]
3  [ 1 1 1 1 ]

*/

void findPath(vector<vector<int>> &maze, int row, int col, string path, vector<vector<bool>> &vis, vector<string> &ans)
{
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze.size() || maze[row][col] == 0)
        return;
    if (maze[row][col] == -1)
        return;

    if (row == maze.size() - 1 && col == maze.size() - 1)
        ans.push_back(path);

    maze[row][col] = -1;

    findPath(maze, row - 1, col, path + "U", vis, ans);
    findPath(maze, row + 1, col, path + "D", vis, ans);
    findPath(maze, row, col - 1, path + "L", vis, ans);
    findPath(maze, row, col + 1, path + "R", vis, ans);

    maze[row][col] = 1;
}

void rat_in_maze(vector<vector<int>> &maze, vector<string> &ans)
{
    int n = maze.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string path;
    findPath(maze, 0, 0, path, vis, ans);
}

void rat_in_a_maze_()
{
    vector<vector<int>> maze = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {0, 0, 0, 1},
                                {0, 0, 0, 1}};

    vector<string> ans; //= {"sdfg","werfg"};
    rat_in_maze(maze, ans);
    for (string str : ans)
    {
        cout << str << endl;
    }
    // return 0 ;
}

// Palindrone partioning
bool ispalindrone(string s)
{
    int st = 0, end = s.size() - 1;
    while (st <= end)
    {
        if (s[st++] != s[end--])
            return false;
    }
    return true;
}

void helper(string s, vector<string> &palindrones, vector<vector<string>> &ans)
{
    if (s.empty())
    {
        ans.push_back(palindrones);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i + 1);
        if (ispalindrone(part))
        {
            palindrones.push_back(part);
            helper(s.substr(i + 1), palindrones, ans);
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> palindrones;
    vector<vector<string>> ans;
    helper(s, palindrones, ans);
    return ans;
}

// Merge sort
/*
It works on the base of divide and concur
divide the array by the middle until we get one element in the recursion tree and sort the elements as backtrakking
*/

void merge(vector<int> &nums, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (nums[i] > nums[j])
        {
            temp.push_back(nums[j]);
            j++;
        }
        else
        {
            temp.push_back(nums[i]);
            i++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for(int idx = 0 ;idx<temp.size();idx++){
        nums[idx+start] = temp[idx];
    }
}

void sortHelper(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start ) / 2;

        sortHelper(nums, start, mid);   // Left half
        sortHelper(nums, mid + 1, end); // right half
        merge(nums, start, mid, end);
    }
}

vector<int> merge_sort(vector<int> &nums)
{
    int st = 0,end = nums.size()-1;
    sortHelper(nums,st,end);
    return nums;
}
/*
    QUICK SORT : Quick Sort is a divide-and-conquer sorting algorithm.

-> Pick a pivot : Choose one element from the array (commonly the first, last, middle, or random element).

-> Partition the array : Rearrange elements so that:
                        - All elements smaller than pivot go to the left.
                        - All elements greater than pivot go to the right.
-> Recursively sort the left and right subarrays.
-> When subarrays are size 0 or 1 → they’re already sorted.
*/
int pivotFind(vector<int> &nums,int start,int end){
    int pivot = nums[end];
    int idx = start;
    for(int i = start ; i< end ; i++){
        if(nums[i] <= pivot){
            swap(nums[i],nums[idx]);
            idx++;
        }
    }
    swap(nums[end],nums[idx]);
    return idx;
}
void quick_sort_helper(vector<int>&nums , int start , int end){
    if(start<end){
        int pivot = pivotFind(nums,start,end);
        quick_sort_helper(nums,start,pivot-1);
        quick_sort_helper(nums,pivot+1,end);
    }
}
vector<int> quick_sort(vector<int>& nums){
    quick_sort_helper(nums,0,nums.size()-1);
    return nums;
}

//Removing duplicates from an array using recursion
void making_unique(vector<int> &nums,int start,int idx){
    for(int i = idx ; i>start ; i--){
         nums.erase(nums.begin()+i);
    }
}

void helper(vector<int>&nums,int start,int end){
    if(start>=end || nums.size() <= 1)return;
    int i = start;
    while(i<end && nums[i] == nums[i+1]){
        i++;
    }
    //helper(nums,start,i);
    helper(nums,i+1,end);
    making_unique(nums,start,i);
}

void removeDuplicatesHelper(vector<int>& nums){
    helper(nums,0,nums.size()-1);
}
int main(){
    vector<int> nums = {1,1,2};
    removeDuplicatesHelper(nums);
    for(int val:nums){
        cout<< val <<" ";
    }
    cout<<nums.size()<<endl;
    return 0;
}