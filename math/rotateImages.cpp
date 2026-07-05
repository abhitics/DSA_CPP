#include<iostream>
#include<vector>
using namespace std;

/*
Problem: Rotate Image (90° Clockwise)

Approach:
1. Transpose matrix
2. Reverse every row

Time: O(n²)
Space: O(1)
*/

void rotate(vector<vector<int>>& matrix){
    int n=matrix.size();

    // Transpose
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // Reverse each row
    for(int k=0;k<n;k++){
        int i=0;
        int j=n-1;

        while(i<j){
            swap(matrix[k][i],matrix[k][j]);
            i++;
            j--;
        }
    }
}

void print(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    vector<vector<int>> matrix={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout<<"Original Matrix:\n";
    print(matrix);

    rotate(matrix);

    cout<<"\nRotated Matrix:\n";
    print(matrix);

    return 0;
}