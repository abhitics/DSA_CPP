#include <iostream>
#include <vector>
using namespace std;
int main() {
    int  r1,r2,c1,c2,i,j,k;
    cout<<"Enter the row of first array: ";
    cin>>r1;
    cout<<"Enter the column of first array: ";
    cin>>c1;
    cout<<"Enter the row of second array: ";
    cin>>r2;
    cout<<"Enter the column of second array: ";
    cin>>c2;
    vector<vector<int>> arr(r1, vector<int>(c1));
    vector<vector<int>> brr(r2, vector<int>(c2));
    vector<vector<int>> crr(r1, vector<int>(c2, 0));
    if(c1!=r2)   cout<<"Matrix multiplication is not possible";
    else{
        cout<<"Enter elements of first matrix: ";
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Enter elements of second matrix: ";
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            cin>>brr[i][j];
        }
    }
    int sum=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            crr[i][j]=0;
            for(k=0;k<r2;k++)
            {
                crr[i][j]+=arr[i][k]*brr[k][j];
            }
        }
    }
for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            cout<<crr[i][j]<<" ";
        }
    }    }
    return 0;
}
