#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int pow(int a,int b){
    if(b==0)  return 1;
    if(b==1)  return a;
    if(b%2==0)    return pow(a,b/2)*pow(a,b/2);
    return pow(a,b/2)*pow(a,b/2)*a;
}

int main(){
    int a,b;
    cout<<"Enter the value of a and b";
    cin>>a>>b;
    pow(a,b);
    return 0;
}