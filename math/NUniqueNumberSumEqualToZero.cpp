#include<iostream>
#include<vector>
using namespace std;

/*
Problem:
Find N Unique Integers Sum up to Zero

Approach:
Add pairs:
(i,-i)

If n is odd:
add 0

Time: O(n)
Space: O(n)
*/

vector<int> sumZero(int n){

    vector<int> ans;

    for(int i=1;i<=n/2;i++){
        ans.push_back(i);
        ans.push_back(-i);
    }

    if(n%2==1)
        ans.push_back(0);

    return ans;
}

int main(){

    int n;

    cout<<"Enter n: ";
    cin>>n;

    vector<int> ans=sumZero(n);

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}