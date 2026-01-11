#include <iostream>
using namespace std;

//////////////////   <<<BINARY NUMBERS>>>    ////////////////////

// decimal to binary
 int dec_to_binary(int a){
    int rem ,num=0 ,pow = 1; // initialise num = 0 because it has garbage value
    while(a>0){
        rem = a%2;
        a /=2;
        num += (rem *pow) ;
        pow *= 10;
    }
    return num;
 }

namespace decTOBin{
 void conversion(){
    for(int i = 0;i<=1000;i++){
    cout<< i<<" : " << dec_to_binary(i)<<endl;
        }
    }
}

//Binary to decimal
int binary_to_dec(int a){
    int rem ,num=0 ,pow = 1; // initialise num = 0 because it has garbage value
    while(a>0){
        rem = a%10;
        a /=10;
        num += (rem *pow) ;
        pow *= 2;
    }
    return num;
}
namespace BinTODec{
    void conversion(){
       for(int i = 0;i<=10;i++){
        int b = dec_to_binary(i);
        cout<< b <<" : " << binary_to_dec(b)<<endl;
        }
    }
}

/*
-> 1's complement (0->1,1->0)
-> 2's complement (for negative numbers)
  ~ find 1's complement 
  ~ add 1 in binary addition
*/

//////// <<< BINARY EXPONENTIAL (FINDING (X)^N OPTIMACALLY ) >>> //////////
// (x)^n
int binary_exponential(int x,int n){ // x = base  ,  n = power 
    /*
    1. firstly we will convert n to binary one digit at a time
    2. then check wheather it is 1 or zero
    3. if 1 then multiply it to ans if not then assign its value x*=x
    4. handle negative input (if power is negative do the reciprocal of x)

    */
   long binary = n ;
   int ans = 1;

   if(binary==0){ //when power is zero
    return 1;
   }

   if(x==1){ // when integer is 1 
    return 1;
   }

   if(binary==-1){ // wghen power is negative
    x = 1/x;
    binary = - binary;
   }

   if(x==-1){ // when integer is negative 
    if(binary%2==0){
        return 1;
    }
    if(binary%2 !=0){
        return -1;
    }
   }
   
   while(binary>0){
    if(binary%2==1){
        ans*=x;
    }
    x*=x;
    binary /=2;
   }
   return ans;
}

