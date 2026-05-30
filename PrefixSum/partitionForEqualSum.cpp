#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={7,3,9,4,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool flag=false;
    for(int i=0;i<n;i++){  //Prefix sum
        
        if(i>0) arr[i]=arr[i-1]+arr[i];
    }
    for(int i=0;i<n;i++){  
        
        if(2*arr[i]==arr[n-1]) flag=true ;
    }
    cout<<flag;
}



