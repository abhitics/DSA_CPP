#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>>v0(3,vector<int> (4,20));
    int i,j;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<v0[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<v0.size()<<endl; //size of row
  
  for(i=0;i<3;i++){
      cout<<v0[i].size()<<endl; 
  }
    cout<<v0[2].size()<<endl;   //size of column,in v1[] it will take indices of rows
    // cout<<v0[i].size();    this will give error without 'i'
    cout<<endl;
    cout<<endl;
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    
    vector<int>v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    
    vector<int>v3;
    v3.push_back(9);
    v3.push_back(10);
    
    vector<vector<int>>v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    for(i=0;i<3;i++)
    {
        cout<<v[0][i]<<" ";
    }cout<<endl;
    cout<<v[0].size()<<" ";
    cout<<endl;
    for(i=0;i<5;i++)
    {
        cout<<v[1][i]<<" ";
    }cout<<endl;
    cout<<v[1].size()<<" ";
    cout<<endl;
    for(i=0;i<2;i++)
    {
        cout<<v[2][i]<<" ";
    }cout<<endl;
    cout<<v[2].size()<<" ";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    v[0].push_back(4);
    for(i=0;i<4;i++)
    {
        cout<<v[0][i]<<" ";
    }
    cout<<endl;
    vector<int>v4 = {1, 23 , 34};
    v.push_back(v4);   //taking input another vector v4
    cout<<v[3][1];   // 1 index of v4

    
}
    
