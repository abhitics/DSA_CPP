#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={7,3,9,4,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int prevSum=0;
    int maxSum=INT_MIN;
    int maxIdx=-1;
    for(int i=0;i<k;i++){
        prevSum+=arr[i];
    }
    maxSum=prevSum;
    int i=1;
    int j=k;
    int currSum=0;
    while(j<n){
        currSum=prevSum+arr[j]-arr[i-1];
        if(maxSum<currSum){
            maxSum=currSum;
            maxIdx=i;
        }
        prevSum=currSum;
        i++;
        j++;
    }
    cout<<maxSum;
    cout<<maxIdx;
}



