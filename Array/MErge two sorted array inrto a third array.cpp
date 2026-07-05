#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void mergesorted(vector<int>& v1,vector<int>& v2,vector<int>& v3,int n,int m)
{
    int i=n-1;
    int j=m-1;
    int k=m+n-1;        //merge two sorted array into a third array
    while(i>=0 && j>=0){
        if(v1[i]<v2[j]) {
            v3[k]=v2[j];
            k--;
            j--;
        }
        else {
            v3[k]=v1[i];
            k--;
            i--;
        }
    }
    while(j>=0){
        v3[k]=v2[j];
        k--;
        j--;
    }
     while(i >= 0){
        v3[k]=v1[i];
        k--;
        i--;
    }
}
int main(){
    int n,m,i,j,k;
    // vector<int>v1;
    // vector<int>v2;
    vector<int>v1;
    vector<int>v2;
    
    cout<<"Enter the number of terms of first array: ";
    cin>>n;
    cout<<"Enter the number of first array: ";
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;      
        v1.push_back(x);
    }
    cout<<"Enter the number of terms of second array: ";
    cin>>m;
    cout<<"Enter the number of second array: ";
    for(i=0;i<m;i++)
    {
        int x;
        cin>>x;      
        v2.push_back(x);
    }
    
    vector<int>v3(n+m);
    mergesorted (v1,v2,v3,n,m);
     for(k=0;k<n+m;k++)
    {
        cout<<v3[k]<<" ";
    }
}



