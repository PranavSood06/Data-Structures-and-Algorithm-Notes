#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

//  <<< BUBBLE SORT >>>

/*
    So in it when we do a dry run it will compare the first element with the adajacent
    element and if it is greater then it will  swap it making the largest to go to at the
    end ... so we need not to check the last element so we run our outer loop to nums.size()-1... ^^
*/

vector<int> Bubble_sort(vector <int>& nums){ // O(n^2)
    for(int i = 0;i<nums.size()-1;i++){

    bool isSwap = false;

        for(int j = 0;j<(nums.size()-i-1);j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                isSwap =true;
            }
        }
    
    if(!isSwap){
        return nums;
    }

    } 
    return nums;
}


// <<<< SELECTION SORT >>>>

/*
In it we will select the smallest element -> track its index -> swap it with i=0;i++
*/

vector<int> SELECTION_SORT(vector<int>& nums){ // O(n^2)
    for(int i = 0 ;i<(nums.size()-1);i++){
        int small = i;
        for(int j = i+1;j<nums.size();j++){
           if(nums[j]<nums[small]){
            small = j;
           }
        }
        swap(nums[small],nums[i]);
    }
    return nums;
}


// <<<< INSERTION SORT >>>>

vector<int> INSERTION_SORT(vector<int>& nums){
    for(int i =0;i<nums.size();i++){
        int curr = nums[i],prev = i-1;
        while(nums[prev]>curr && prev>=0){
            nums[prev+1] = nums[prev];
            prev--;
        }
        nums[prev+1] = curr;
    }
    return nums;
}


// <<<<< MERGE TWO SORTED ARRAYS >>>>>>


int main(){
    vector<int> nums = {5,4,3,2,1};
    INSERTION_SORT(nums);
    for(int val:nums){
        cout<<val<<" ";
    }
}