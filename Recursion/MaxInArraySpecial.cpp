#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
int Max(vector<int>& v,int i){
   if(i==v.size()) return INT_MIN;
   return max(v[i],Max(v,i+1));
}

int main(){
    int arr[]={4,3,8,1,2,0,9,5,1000};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(n);
    for(int i=0;i<n;i++) v[i]=arr[i];
    cout<<Max(v,0);
    return 0;
}