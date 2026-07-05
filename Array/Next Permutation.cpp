#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPerm(vector<int>& v)   //NEXT PERMUTATION  
{
    int n=v.size();
    int idx=-1;   // 1) find Pivot Index
    for(int i=n-2;i>=0;i--)
    {
        if(v[i]<v[i+1])  {
            idx=i;
            break;
        }
    }
    if(idx==-1)  {
        reverse(v.begin(),v.end());
        return;
        
    }
    //reverse elements from index (idx+1) to end
    reverse(v.begin()+idx+1,v.end());
    //swap idx number to just greater to idx index number
    int j=-1;
    for(int i=idx+1;i<n;i++){
        if(v[idx]<v[i])    
        j=i;
        break;
        }
    
    swap(v[idx],v[j]);
}
int main(){
    int n,i;
    vector<int>v;
    cout<<"Enter the number of terms of array: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;      
        v.push_back(x);
    }
    nextPerm(v);
     for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}



