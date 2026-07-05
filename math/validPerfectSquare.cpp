#include<iostream>
using namespace std;

/*
Problem:
367. Valid Perfect Square

Approach:
Use Binary Search.

Search for number whose:
mid*mid==num

If square smaller:
move right

If square larger:
move left

Use long long
to avoid overflow.

Time: O(logn)
Space: O(1)
*/

bool isPerfectSquare(int num){

    long long low=1;
    long long high=num;

    while(low<=high){

        long long mid=low+(high-low)/2;

        long long sq=mid*mid;

        if(sq==num) return true;

        if(sq<num) low=mid+1;
        else high=mid-1;
    }

    return false;
}

int main(){

    int num;
    cin>>num;
    if(isPerfectSquare(num)) cout<<"true";
    else cout<<"false";

    return 0;
}