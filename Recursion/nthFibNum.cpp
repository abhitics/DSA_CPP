#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int nthFib(int a){
    if(a==1 || a==2){
        return 1;
    }
    return nthFib(a-1)+nthFib(a-2);
}

int main(){
    int a,b;
    cout<<"Enter the nth number";
    cin>>a;
    nthFib(a);
    return 0;
}