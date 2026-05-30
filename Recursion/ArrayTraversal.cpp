#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
void display(int arr[],int n,int i){
    if(i==n) return;
    cout<<arr[i]<<" ";
    display(arr,n,i+1);
}
int main(){
    int arr[]={4,3,8,1,2,0,9,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n,0);
    return 0;
}