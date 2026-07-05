#include<iostream>
#include<vector>
using namespace std;

/*
Problem:
Check If It Is a Straight Line

Approach:
Use cross multiplication

(y-y0)*dx = dy*(x-x0)

Avoids division and slope precision issues

Time: O(n)
Space: O(1)
*/

bool checkStraightLine(vector<vector<int>>& nums){

    int x0=nums[0][0];
    int y0=nums[0][1];

    int x1=nums[1][0];
    int y1=nums[1][1];

    int dx=x1-x0;
    int dy=y1-y0;

    for(int i=2;i<nums.size();i++){

        int x=nums[i][0];
        int y=nums[i][1];

        if((y-y0)*dx!=dy*(x-x0))
            return false;
    }

    return true;
}

int main(){

    vector<vector<int>> nums={
        {1,2},
        {2,3},
        {3,4},
        {4,5},
        {5,6}
    };

    if(checkStraightLine(nums))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}