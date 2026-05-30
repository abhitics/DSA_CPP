#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int num=12;
    string res="";
    while(num>0){
        if(num%2==0) res+="0";
        else res+="1";
        num/=2;
    }
    cout<<res;
}

