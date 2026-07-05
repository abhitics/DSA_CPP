#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m,x,i,j;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    cout<<"Enter elemnts of vector: ";
     vector<vector<int>>v(n,vector<int>(m));
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             cin>>v[i][j];
         }
     }
     cout<<"Enter the target: ";
     cin>>x;
      i=0;
      j=m-1;
     while(i<n && j>=0){
        if(v[i][j]==x)    break;
        else if(v[i][j]>x)  j--; // go left
        else i++; //go down
     }
     cout<<x<<" found at i="<<i<<" and j="<<j;
}
    
