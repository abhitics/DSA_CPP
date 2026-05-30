#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
void Max(int arr[],int n,int i,int max){
    if(n==i) {
        cout<<max; return;
    }
    if(arr[i]>max) max=arr[i];
    Max(arr,n,i+1,max);
}

int main(){
    int arr[]={4,3,8,1,2,0,9,5,1000};
    int n=sizeof(arr)/sizeof(arr[0]);
    Max(arr,n,0,INT_MIN);
    return 0;
}