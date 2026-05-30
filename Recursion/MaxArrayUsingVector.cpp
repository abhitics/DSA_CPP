#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
void Max(vector<int>& v,int i,int max){
    if(v.size()==i) {
        cout<<max; return;
    }
    if(v[i]>max) max=v[i];
    Max(v,i+1,max);
}

int main(){
    int arr[]={4,3,8,1,2,0,9,5,1000};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(n);
    for(int i=0;i<n;i++) v[i]=arr[i];
    Max(v,0,INT_MIN);
    return 0;
}