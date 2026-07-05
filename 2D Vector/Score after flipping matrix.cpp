#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m,i,j;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    cout<<"Enter score in binary: ";
     vector<vector<int>>v(n,vector<int>(m));
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             cin>>v[i][j];
         }
     }
     for(i=0;i<n;i++) //traversing in first column if any is zero flip that column
     {
         if(v[i][0]==0){
             for(j=0;j<m;j++)
             {
                 if(v[i][j]==0)  v[i][j]=1;
                 else  v[i][j]=0;
             }
         }
     }
     //flip the columns where noz>noo
     for(j=0;j<m;j++)
     {
         int noz=0;
         int noo=0;
         for(i=0;i<n;i++)
         {
             if(v[i][j]==0)  noz++;
             else   noo++;
         }
         if(noz>noo)
         {
             for(i=0;i<n;i++)
             {
                if(v[i][j]==0)  v[i][j]=1;
                else  v[i][j]=0;
             }
         }
     }cout<<endl;
     //after this we have get the maximum score matrix now convert each row in decimal and add them....
     
     int sum=0;  //BINARY TO DECIMAL
     for(i=0;i<n;i++)
     { 
         int x=1;
         for(j=m-1;j>=0;j--)
         {
             sum += v[i][j]*x;
             x *= 2;
         }
     }
     cout<<"Maximum score is "<<sum;
}
    
