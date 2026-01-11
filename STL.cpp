/*
Deque 
 - push_back --- add a element from back
 - push_front --- add a element from front
 - pop_front --- remove element from front
 - pop_back() -- removes the last element
 - .at(index) -- gives the element with index
 - front() --- gives the first element
 - back() --- gives the last element 
 - begin() --- returns iterator pointing to the first element
 - end() --- returns iterator pointing to the last element
 - erase(intial_iterator,ending iterator) --- will erase that subarray
*/
#include<iostream>
#include<iomanip>
#include<vector> // for vector 
#include<deque> // for deque
#include<list> // for list
#include<algorithm>
using namespace std;

class name{

};

int main(){
    deque<int> nums= {1,2,3,4,5,6,7,8,9,10};
    nums.push_back(11);
    nums.push_front(0);
    for (int val:nums){
        cout<<val<<" ";
    }
    //cout<<"\n"<<nums.at(0);
    //nums.pop_back();
    nums.erase(nums.begin()+1);
    cout<<"\n";
    for (int val:nums){
        cout<<val<<" ";
    }
    return 0;
}