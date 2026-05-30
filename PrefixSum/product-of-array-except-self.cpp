#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // int arr[]={1,2,3,4};    // will work if there is no zero in array
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int pro=1;
    // for(int i=0;i<n;i++){
    //     pro*=arr[i];
    // }
    // for(int i=0;i<n;i++){
    //     cout<<pro/arr[i]<<" ";
    // }


    // int arr[]={1,2,3,4,0};   //if there is zeros in array
    // int n=sizeof(arr)/sizeof(arr[0]); 
    //     int pro=1;      
    //     int pro2=1;     
    //     int noz=0;
    //     for(int i=0;i<n;i++){
    //         if(arr[i]==0) 
    //             noz++;
    //         pro*=arr[i]; 
    //         if(arr[i]!=0)   pro2*=arr[i];
    //     }
    //     if(noz>1)   pro2=0;
    //     for(int i=0;i<n;i++){
    //         if(arr[i]==0) arr[i]=pro2;
    //         else arr[i]=pro/arr[i];
    //     }
    //     for(int i=0;i<n;i++){
    //         cout<<arr[i]<<" ";
    //     }




        int a[]={1,2,3,8,4};   
        int n=sizeof(a)/sizeof(a[0]); 
        int pre[n];
        int suf[n];
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*a[i-1];
        }
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*a[i+1]; 
        }
        for(int i=0;i<n;i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<suf[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            a[i]=pre[i]*suf[i];
            cout<<a[i]<<" ";
        }
        cout<<endl;

}



