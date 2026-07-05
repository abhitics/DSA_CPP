#include<iostream>
#include<cmath>
using namespace std;

/*
Problem:
650. 2 Keys Keyboard

Approach:
Think in reverse (n → 1)

If n is prime:
answer=n

Otherwise:
Find smallest factor i

n=i×(n/i)

operations:
i+minSteps(n/i)

Example:
n=12

12=2×6
=2+2×3
=2+2+3
=7

Time: O(√n)
Space: O(logn)
*/

bool isPrime(int n){

    if(n<=1)
        return false;

    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }

    return true;
}

int minSteps(int n){

    if(n==1)
        return 0;

    if(isPrime(n))
        return n;

    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return i+minSteps(n/i);
    }

    return 0;
}

int main(){

    int n;

    cout<<"Enter n: ";
    cin>>n;

    cout<<minSteps(n);

    return 0;
}