#include<iostream>
using namespace std;

/*
Problem:
1323. Maximum 69 Number

Approach:
Recursion

Go to leftmost digit.
Change first 6 → 9.
Keep remaining digits unchanged.

Time: O(log n)
Space: O(log n)
*/

int maximum69Number(int num){

    if(num==0) return 0;
    int x=maximum69Number(num/10);
    if(x==num/10 && num%10==6) return x*10+9;
    return x*10+num%10;
}

int main(){
    int num;
    cout<<"Enter number: ";
    cin>>num;
    cout<<"Maximum Number: "<<maximum69Number(num)<<endl;
    return 0;
}