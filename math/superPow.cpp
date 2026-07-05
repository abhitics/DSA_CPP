#include<iostream>
#include<vector>
using namespace std;

/*
Approach:
Process exponent digit by digit.

Example:
a^123

= ((a^1)^10 × a^2)^10 × a^3

For every digit:
1. Raise previous result to power 10
2. Multiply with a^(current digit)
3. Take modulo 1337

Time: O(n)
Space: O(1)
*/

int power(int a,int b){
    int res=1;
    a%=1337;
    while(b--)  res=(res*a)%1337;
    return res;
}
int superPow(int a,vector<int>& b){
    int result=1;
    for(int digit:b){
        result=power(result,10);
        result=(result*power(a,digit))%1337;
    }
    return result;
}

int main(){
    int a,n;
    cin>>a>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    cout<<superPow(a,b);

    return 0;
}