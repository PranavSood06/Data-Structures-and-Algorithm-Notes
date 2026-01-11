#include <iostream>
#include<limits>
#include<vector>
#include<algorithm>
using namespace std;
/*
Arrays
->same type
->continuous in memory 
*/
void largsmall(){
    int marks[5]= {15,-52,35,54,85};
    int large = INT_MAX;
        for(int i = 0;i<5;i++){
            if(marks[i]<large){
                large=marks[i];
            }
        }
        for(int i = 0;i<5;i++){
            cout<<large<<endl;
        }
}

//arrays are pointers
void changearr(int arr[],int size){
    cout<<"In Chanarr function"<<endl;
    for(int i = 0 ;i<size;i++){
        arr[i]*=2;
        cout<<arr[i]<<endl;
    }
}

void arraypointers(){
    int arr[5]={11,15,45,24,85};
    changearr(arr,5);
    cout<<"In Main function"<<endl;
    for(int i = 0 ;i<5;i++){
        cout<<2*arr[i]<<endl;
    } 
}

/////////////////////////////////////////////////////////////////////////////////

//    <<<< LINEAR SEARCH ALGORITHM >>>>      //
class LSA{
    public:
    int target_check(int arr[],int size,int target){
        for(int i = 0 ; i<size ;i++){
            if(arr[i]==target){
                return (i+1);
            }
        }
        return -1;
    }
};

void checking(){
    int arr[]={11,55,85,74,-98,8,75,41};
    LSA obj;
    int a =obj.target_check(arr,sizeof(arr)/sizeof(int),88);
    std::cout<<a<<endl;
}
/////////////////////////////////////////////////////////////////////////////////

//    <<< 2 pointer approach >>>   //
void revarray(){
    int arr[5] = {12,52,45,78,96};
    int start = 0 ;
    int end = (sizeof(arr)/sizeof(int))-1;
    int size = end +1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i = 0 ; i<size; i++){
        cout<<arr[i]<<endl;
    }
}

///////////////  << KADANE'S ALGORITHM >>    ////////////////

/*

The continuous part of array is called subarray
Eg : {1,2,3,4,5,6}
subarray can be :
{1}
{12}
{123}
{1234}
{12345}
{123456}

Total subarrays of n element array is given by :
n*(n+1)/2 

*/

// Brute force way to print all subarrays
void subarrayss(){
    vector<int> num = {1,2,3,4,5};
    // all subarrays of a given array can be printed out in this way
    for(int start = 0 ; start<num.size() ; start++){
        for(int end = start ; end<num.size() ; end++){
            for(int i = start ; i<=end ; i++){
                cout<<num[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

/*
In kadane algorithm we can find the maximum of the subarray in just one loop...we will simply add it to sum = 0 one by one 
and then check the maximum by the previous maximum .... if the number goes negative we can just change the sum to zero 
*/

void kadane_algorithm(){
    vector<int> nums = {0,-1,-2,-3,-4,-5};
    int sum=0,maxsum = INT_MIN;
    for(int val: nums){
        sum+=val;
        maxsum = max(sum,maxsum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxsum;
}

/////////////// <<<< MAJORITY ELEMENT >>>> ////////////////////
//the element which comes more than size/2 times is called majority element

// Brute force
void brute_FORCE_approach(){
    vector <int> arr = {10,10,10,5,10,2,10,2,10,5,5,5,10,10};
    int size = arr.size(),count = 0 ;
    for(int val:arr ){
        for(int ele:arr ){
            if(val==ele){
                count++;
            }
        } 
        if(count>size/2){
            cout<< val;
            break;
        }       
    }
}

//optimise approach
void optimal(){
    vector <int> arr = {10,10,10,5,10,2,10,2,10,5,10,5,10,10};
    sort(arr.begin(),arr.end());
    int size = arr.size(),freq=1,ME=0; // freq -> frequency  ME ->Majority element
    for(int i =1;i<size;i++){
        if(arr[i]==arr[i-1]){
            freq++;
        }
        else{
            freq =1;
        }
        if(freq>size/2){
            ME = arr[i-1];
            break;
        }   
    }
    cout<<ME;
}

//best approach
//            <<< MOORE'S VOTING ALGORITHM >>>
/*
frequency of majority element can never be zero 
image a array of 4 - x and 3 - y
{x,x,x,x,y,y,y}
4-3 = 1
*/
void best  (){
    vector <int> num = {10,10,10,5,10,2,10,2,10,5,10,5,10,10};
    int freq = 0 , ans = 0 ;
    for(int i = 0 ; i<num.size();i++){
        if(freq == 0){
            ans = num[i];
        }
        if(ans==num[i]){
            freq++;
        }
        else{
        freq--;
        }
    }
    cout<<ans;
// check the count if there is saying to return -1 in no majority element    
}

/*
To find the product of an array we can use suffix and prefixes of it ..... finding the prefixes ans multiplying it on ans vector 
*/

/*
to understand max min product in subarray check queston 138
*/