#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={7,3,9,4,1,2};
    int n=6;
    for(int i: arr){
        cout<<i<<" ";
    }
    for(int i=0;i<n-1;i++){    //n-1 passes
        int min= INT_MAX;
        int mindx=-1;
        for(int j=i;j<n;j++)   //minimum element calculation in box
        {
            if(arr[j]<min){
                min=arr[j];
                mindx=j;
            }
        }
        swap(arr[i],arr[mindx]);
    }
    cout<<endl;
    for(int i: arr){
        cout<<i<<" ";
    }
}



