#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={7,3,9,4,1,2};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i] <<" ";
    }
    for(int i=0;i<n-1;i++){    //n-1 passes
        for(int j=0;j<n-i-1;j++)   //traverse
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i] <<" ";
    }
}



