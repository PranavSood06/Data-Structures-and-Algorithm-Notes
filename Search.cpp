#include<iostream>
#include<vector>
using namespace std ; 

//////////////////    <<<< BINARY SEARCH >>>>     //////////////////////////////////////
int search(vector<int>& arr,int target){
    int start=0,end=arr.size()-1,mid;
    while(start<=end){
        mid = start + (end - start)/2; // to avoid overflow by 
        if(arr[mid]==target){
            return mid+1;
        }
        if(arr[mid]<target){
            start = mid +1;
        }
        if(arr[mid]>target){
            end = mid -1;
        }
    }
    return -1;
}


// Using Recursion
int Search_Using_Recursion(vector<int>& arr,int target,int start,int end){
    if(start>end){
        return -1 ; 
    }
        int mid = start + (end - start)/2; // to avoid overflow by 
        if(arr[mid]==target){
            return mid+1;
        }
        if(arr[mid]<target){
            return Search_Using_Recursion(arr,target,mid+1,end);
        }
        if(arr[mid]>target){
            return Search_Using_Recursion(arr,target,start,mid-1);
        }
    return -1;
}


/////////////////////////// <<<< Searching in Rotated sorted array >>>>  /////////////////////////////
int Rotated_Sorted_Array(vector<int>& nums,int target){
    int start=0,end = nums.size()-1;
    while(start<=end){
    int mid = start + (end -start)/2;
    if(target == nums[mid]){
        return mid;
    }
    if(nums[start]<=nums[mid]){
        if(nums[start]<=target && target<=nums[mid]){
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }else{
        if(nums[mid]<=target && target<=nums[end]){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
    }
    }
    return -1;
}

int main(){
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
    cout<<Rotated_Sorted_Array(arr,9);
}