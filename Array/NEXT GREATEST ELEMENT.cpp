#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,i;
    vector<int>v;   //NEXT GREATEST ELEMENT
    cout<<"Enter the number of terms of array: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;      
        v.push_back(x);
    }
    vector<int>v1(n);
    int max=v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        v1[i]=max;
        if(max<v[i])  max=v[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<" ";
        if(i==n-1)  v1[i]=-1;
    }
}



