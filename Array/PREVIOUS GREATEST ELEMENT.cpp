#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,i;
    vector<int>v;   //PREVIOUS GREATEST ELEMENT
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
    int max=v[0];
    for(int i=1;i<n;i++)
    {
        v1[i]=max;
        if(max<v[i])  max=v[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<" ";
        if(i==0)  v1[i]==-1;
    }
}



