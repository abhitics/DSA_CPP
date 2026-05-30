#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={7,3,9,4,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        
        if(i>0) arr[i]=arr[i-1]+arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}



