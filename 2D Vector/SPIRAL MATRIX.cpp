#include <iostream>
#include <vector>
using namespace std;
int main() {
    int  n,m,i,j;
    cout<<"Enter the row of array: ";
    cin>>n;
    cout<<"Enter the column of array: ";
    cin>>m;
    int arr[n][m];
    cout<<"Enter elements of matrix: ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int minr=0,maxr=n-1;
    int minc=0,maxc=m-1;
    int count=0,limit=n*m;
    while(minr<=maxr && minc<=maxc){
    //RIGHT
    for(j=minc;j<=maxc && count<limit;j++){
        cout<<arr[minr][j]<<" "; //SPIRAL MATRIX
        count++;
    } minr++;
    //DOWN
    for(i=minr;i<=maxr && count<limit;i++){
        cout<<arr[i][maxc]<<" ";
        count++;
    } maxc--;
    //LEFT
    for(j=maxc;j>=minc && count<limit;j--){
        cout<<arr[maxr][j]<<" ";
        count++;
    } maxr--;
    //TOP
    for(i=maxr;i>=minr && count<limit;i--){
        cout<<arr[i][minc]<<" ";
        count++;
    }minc++;
    }
}
