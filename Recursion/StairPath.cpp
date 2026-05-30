#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int stair(int a){
    if(a==0)    return 1;  //at ground 
    if(a==1)    return 1;  // at first stair
    return stair(a-1)+stair(a-2);    //ways to reach nth stair is sum of ways to reach (n-1)th and (n-2)th stair
}

int main(){
    int a;
    cout<<"Enter the number of stairs if he climbs 1 or 2 steps at a time: ";
    cin>>a;
    cout<<stair(a);
    return 0;
}