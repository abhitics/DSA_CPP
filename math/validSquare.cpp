#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Problem:
593. Valid Square

Approach:
Calculate squared distance
for all 6 pairs.

For a valid square:
- 4 equal sides
- 2 equal diagonals
- side > 0

Example:

(0,0)
(1,0)
(1,1)
(0,1)

Distances:
1 1 1 1 2 2

Time: O(1)
Space: O(1)
*/

int dist(vector<int>& a,vector<int>& b){
    int dx=a[0]-b[0];
    int dy=a[1]-b[1];
    return dx*dx+dy*dy;
}

bool validSquare(vector<int>& p1,vector<int>& p2,vector<int>& p3,vector<int>& p4){
    vector<int> d;
    d.push_back(dist(p1,p2));
    d.push_back(dist(p1,p3));
    d.push_back(dist(p1,p4));

    d.push_back(dist(p2,p3));
    d.push_back(dist(p2,p4));

    d.push_back(dist(p3,p4));

    sort(d.begin(),d.end());
    return d[0]>0 && d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[4]==d[5];
}

int main(){

    vector<int> p1={0,0};
    vector<int> p2={1,1};
    vector<int> p3={1,0};
    vector<int> p4={0,1};

    if(validSquare( p1, p2, p3, p4)) cout<<"true";
    else cout<<"false";

    return 0;
}