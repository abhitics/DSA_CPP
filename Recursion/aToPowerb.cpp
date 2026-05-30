#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int power(int a,int b){
    if(b==0){
        return 1;
    }
    int ans=a*power(a,b-1);
    return ans;
}

int main(){
    int a,b;
    cout<<"Enter the value of a and b";
    cin>>a>>b;
    power(a,b);
    return 0;
}