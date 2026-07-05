#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std; 
// Sieve of Eratosthenes algorithm to count the number of prime numbers less than or equal to n
//TC~~O(nlog(logn)) SC~~O(n)
void fillSieve(vector<bool>& sieve){
    int n=sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){  
        for(int j=i*2;j<=n;j+=i) // Marking all the multiples of i as non-prime
            sieve[j]=false;
    }
} 
int main(){
    int n=100;
    int count=0;
    vector<bool>seive(n+1,true);
    fillSieve(seive);
    seive[0]=false;
    seive[1]=false;
    for(int i=2;i<=n;i++){
        if(seive[i]){
            count++;
        }
    }
    cout<<count;
}