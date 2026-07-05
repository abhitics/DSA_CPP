#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m,i,j,sum=0;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    int arr[n][m];
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           sum+=arr[i][j];
        }
    }
    cout<<"Sum is "<<sum;
}
