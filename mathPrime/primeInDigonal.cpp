#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std; 
    bool isPrime(int n){
        if (n<=1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int main(){
        vector<vector<int>> nums = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
        int n=nums.size();
        int maxP=0;
        for(int i=0;i<n;i++){
            if(isPrime(nums[i][i])){
                maxP=max(maxP,nums[i][i]);
            }
            if(isPrime(nums[i][n-1-i])){
                maxP=max(maxP,nums[i][n-1-i]);
            }
        }
        cout<<maxP;
    }
