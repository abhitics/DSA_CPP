#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

void display(vector<int>& v,int i){
    if(i==v.size()) return;
    cout<<v[i]<<" ";
    display(v,i+1);
}

int main(){
    int arr[]={4,3,8,1,2,0,9,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=arr[i];
    }
    display(v,0);
    return 0;
}