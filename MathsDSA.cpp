#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath> // required for log
using namespace std;

/*
<<< Prime numbers >>>
to check if n is prime or not 
 - check its divisibility by number 2 to sqrt(n)
  - if ==0 then not Prime
  - else Prime
*/

bool isPrime(int a){
    for(int i = 2 ; i*i<=a ;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

// Brute force solution to calculate the number of primes in 0 to n (TLE)
int countPrimes(int n) {
    int count = 0;
    for(int i =2;i<n;i++){
        bool isPrime = true;
        for(int j = 2;j*j<=i;j++){
            if(i%j==0){
                isPrime = false;
            }
        }
        if(isPrime)count++;
    }
    return count;
}

//               <<< Seive of Eratosthenes >>>
// optimal solution to find the count of prime numbers till n (204)
int countPrimes_optimal(int n) {
    // letting all are prime numbers
    vector<bool> isPrime(n+1,true);
    int ans =0;
    for(int i =2;i<n;i++){
        if(isPrime[i]){
            ans++;
            for(int j=i*2;j<n;j+=i){
                // making multiples of i false to shrink the primes
                isPrime[j]=false;
            }
        }
    }
    return ans;
}

//   <<< extracting a digit from number >>>
vector<int> Extrac_digit(int n){
    vector<int> s;
    while(n!=0){ //TC - (O(log10(n))
        int a = n%10;
        s.push_back(a);
        n/=10;
    }
    return s;
}
/*
      <<< In main function >>>

    vector<int> nums = Extrac_digit(789654);
    reverse(nums.begin(),nums.end());
    for(int c:nums){
        cout<<c<<" ";
    }

    one liner :
    cout<<(int)(log10(234)+1)<<endl;
    
*/

//Armstrong number 
// 153 - (1)^3 + (5)^3 +(3)^3 = 153 (armstrong number)

//GCD - Greatest common divisor /HCF
int gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }
    if(a==0)return b;
    return a;
}
// Palaindrone number 
 
// modular Arithmetic 
/*
(x + y) % m = x%m + y%m
(x - y) % m = x%m - y%m
(x . y) % m = x%m . y%m
((x % y) % m)%m... = x%m
*/

//catalan number will be covered in dp 

int main(){
    cout<<gcd(2,1);
    return 0;
}