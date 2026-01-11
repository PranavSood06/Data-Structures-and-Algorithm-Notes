#include <iostream>
#include <iomanip>
using namespace std ; 
int dec_to_binary(int a){
    int rem ,num=0 ,pow = 1;
    while(a>0){
        rem = a%2;
        a /=2;
        num += (rem *pow) ;
        pow *= 10;
    }
    return num;
 }

/*
 & = AND
 | = OR
 ^ = XOR
 The above ones will act as logic gates ..
 << = LEFT SHIFT OPERATOR 
 >> = RIGHT SHIFT OPERATOR
 they are used to shift the number to the left or right resp. in binary
 eg 5<<2
the number 5 in binary will be shifted to left by two places and 2 zeroes will be added to the empty space 
*/

int And(int a , int b){
    return a&b;
}
 void eg_implementation(){
    // eg implementation 
   int b = dec_to_binary(5);
   cout<<" 5 : "<<b<<endl;
   int c = dec_to_binary(5<<2);
   cout<< "5<<2 : "<<c;
 }
 /*
                 <<< IMPORTANT >>>
 << = LEFT SHIFT OPERATOR 
 if we do a<<b then the ans will be
 ans = a*2^b
 >> = RIGHT SHIFT OPERATOR
 if we do a>>b then the ans will be
 ans = a/2^b

 */

// Q - Find out if the number is power of 2 without any loop
bool pow2(int a){
    if((a&(a-1))==0)
        return true;
    else
        return false;
}

// Q - WAF to reverse a number
int main(){
    cout<<pow2(4); // 1 -> true, 0 -> false
    
}