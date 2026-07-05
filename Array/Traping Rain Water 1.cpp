#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,i;
    vector<int>v; //INPUTING MAIN VECTOR
    cout<<"Enter number of terms of array: ";
    cin>>n;    //6
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++){
        int x;
        cin >>x;
        v.push_back(x);  //5 3 10 2 8 6
    }
    vector<int>prev(n);
    int max1=v[0];
    prev[0]=-1;
    for(i=1;i<n;i++)
    {
        prev[i]=max1;
        if(max1<v[i])   max1=v[i];
    }
    cout<<"Previous Greatest element array: ";
    for(i=0;i<n;i++)
    {
        cout<<prev[i]<<" ";  //-1 5 5 10 10 10 
    }
    cout<<endl;
    vector<int>next(n);
    next[n-1]=-1;
    int max2=v[n-1];
    for(i=n-2;i>=0;i--)
    {
        next[i]=max2;
        if(max2<v[i])   max2=v[i];
    }
    cout<<"Next greatest element array: ";
    for(i=0;i<n;i++){
        cout<<next[i]<<" ";  //10 10 8 8 6 -1 
    }
    vector<int>mini(n);
    for(i=0;i<n;i++)
    {
        mini[i]=min(prev[i],next[i]);
    }
    cout<<endl;
    cout<<"Minimum of Next and Prev arrays : ";
    for(i=0;i<n;i++)
    {
        cout<<mini[i]<<" ";
    }
    cout<<endl;
    int sum =0;
    for(i=1;i<n-1;i++)
    {
        if(mini[i]-v[i]>0)   
        {
            sum+=(mini[i]-v[i]);
        }  
    }
    cout<<"Total trapped block are:"<<sum;
}
