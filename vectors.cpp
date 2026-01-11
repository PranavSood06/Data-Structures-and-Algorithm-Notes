#include <iostream>
#include <vector>
using namespace std;
/*
it is just like array but it does not have fixed size
->Syntax
 ~ vector <int> vector_name;
 ~ vector <int> vector_name = {1,2,3,4};
 ~ vector <int> vector_name(3 ,0);
                            |__|__\ Size of vector
                               |  /
                               |
                               |__\ value at every index
                                  /
*/

void syntax_using(){
    vector<char> abcd = {'a','b','c','d'};
    vector<int> num1(4,8);
    /*
    for(int val: num){   <<val is the values at the indexes not the indexes>> it is called for each loop
        cin>>val;
    }
        It cannot be used for reading values it is just for printing / output
    */
   cout<<"\nvector<char> abcd = {'a','b','c','d'} : "<<endl;
   for(char val: abcd){
    cout<<val<<endl;
    }

    cout<<"\nvector<int> num1(4,8) : "<<endl;
   for(int val: num1){
    cout<<val<<endl;
    }

    int n;
    cout<<"\nvector<int> num[n] :\nSize of Vector : ";
    cin>>n;
    vector<int> num(n);
    for(int i = 0 ;i<n;i++){
        cin>>num[i];
    }
    for(int val: num){
        cout<<val<<endl;
        }
    
}


/*                    <<< VECTOR FUNCTIONS >>>
~ size
~ push_back
~ pop_back
~ front
~ back
~ at
~ capacity
~insert(vector.begin()+p,)
*/
void functions(){
    vector<int> num = {12,14,56,85}; 

    cout<<"\nUsing size function : "<<endl;
    cout<<"num.size() : "<<num.size()<<endl; // will tell the size

    cout<<"\nUsing push_back function : "<<endl;
    num.push_back(78); // will insert 78 at the end at run time so we can say vector size is not fixed
    cout<<"num.size() : "<<num.size()<<endl;
    cout<<"num[4] : "<<num[4]<<endl;

    cout<<"\nUsing pop_back function : "<<endl;
    num.pop_back();// will remove the last element
    cout<<"num.size() : "<<num.size()<<endl;

    cout<<"\nUsing front function : "<<endl; 
    cout<<"num.front() : "<<num.front()<<endl; // gives first element as output

    cout<<"\nUsing back function : "<<endl; 
    cout<<"num.back() : "<<num.back()<<endl; // gives last element as output

    cout<<"\nUsing at function : "<<endl;
    cout<<"num.at(2) : "<<num.at(2)<<endl; // gives the element at the index in the bracket as output

    cout<<"\nUsing capacity function : "<<endl;
    cout<<"num.capacity() : "<<num.capacity()<<endl; // when vector is full and push back function is used to insert a value at end the capacity become double 
                                                    //  and number is inserted so size is how many are filled and capacity is how many can be filled...
}

void implement(){
    vector<int> nums = {1,2,3,4,5,6};
   // int* a =  nums.begin();
   // cout <<a<<endl;
 }

/*
in buy and sell stock problems remember :
1. you have to find the minimum to buy and maximum to sell 
2. check each upward movement in prices by buy = min(price[i],price[i-1])
3. increase the profit regularly by profit = price[i]- buy if price [i] > buy
*/

// 2D vectors 
int main(){
    vector<vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    //cout<<"Rows : "<<nums.size()<<"\t"<<"Columns : "<<nums[0].size()<<endl;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            cout<<"["<<i<<","<<j<<"]"<<" ";
        }
        cout<<endl;
    }
    return 0;
}