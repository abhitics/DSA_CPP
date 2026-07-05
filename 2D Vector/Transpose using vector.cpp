#include <iostream>
#include <vector>
using namespace std;
int main() {
    int  r,c,i,j;
    cout<<"Enter the row of array: ";
    cin>>r;
    cout<<"Enter the column of array: ";
    cin>>c;
    
    vector<vector<int>> arr(r, vector<int>(c));
    
    cout<<"Enter elements of matrix: ";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}
