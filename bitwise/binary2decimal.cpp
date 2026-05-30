#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string bin="11001011";
    int n=bin.size();
    int res=0;
    for(int i=n-1;i>=0;i--){
        int num=bin[i]-'0';
        res+=(1<<num*(n-i-1));
    }
    cout<<res;
}

