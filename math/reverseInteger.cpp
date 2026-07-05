#include<iostream>
#include<climits>
using namespace std;

/*
Problem: Reverse Integer

Approach:
1. Extract last digit using %
2. Add digit to reversed number
3. Check overflow before multiplying by 10

Time: O(log10(n))
Space: O(1)
*/

int reverseNumber(int x){
    int rev=0;

    while(x!=0){
        int d=x%10;
        x=x/10;

        // Overflow check
        if(rev<INT_MIN/10 || rev>INT_MAX/10)
            return 0;

        rev=rev*10+d;
    }

    return rev;
}

int main(){

    int x;

    cout<<"Enter number: ";
    cin>>x;

    cout<<"Reversed Number: "
        <<reverseNumber(x);

    return 0;
}