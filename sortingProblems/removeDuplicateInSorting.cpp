#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr = {100, 300, 100, 200};
    vector<int> brr = arr;               // make a copy
    sort(brr.begin(), brr.end());        // sort -> {100, 100, 200, 300}
    brr.erase(unique(brr.begin(), brr.end()), brr.end()); // remove duplicates -> {100, 200, 300}
    int n=brr.size();
    cout<<endl;
    for(int i=0;i<brr.size();i++){
        cout<<brr[i] <<" ";
    }
}



