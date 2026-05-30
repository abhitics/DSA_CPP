#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    //for this just find the last set bit(that is '1') from LSB and then flip after that set bit upto LSB 
    string x="11000100";
    int n=x.size();
    int idx=-1;
    //find the index from where has to flip the binaries
    for(int i=n-1;i>=0;i--){
        if(x[i]=='1'){
            idx=i;
            break;
        }
    }
    for(int i=idx;i<n;i++){
        if(x[i]=='0') x[i]='1';
        else x[i]='0';
    }
    cout<<x;
}


