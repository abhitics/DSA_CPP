#include<iostream>
using namespace std;

/*
Problem:
Sum of Two Integers

Without using + and -

Approach:
Increment/decrement

Time: O(|b|)
Space: O(1)
*/

int getSum(int a,int b){

    if(b>0){
        while(b--)
            a++;
    }
    else{
        while(b++)
            a--;
    }

    return a;
}

int main(){

    int a,b;

    cout<<"Enter first number: ";
    cin>>a;

    cout<<"Enter second number: ";
    cin>>b;

    cout<<"Sum = "
        <<getSum(a,b)
        <<endl;

    return 0;
}