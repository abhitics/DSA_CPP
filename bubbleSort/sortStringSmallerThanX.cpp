//sort a string in decreaing order of values associated after removal of values smaller tham X

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s= "AYZXBDXJK";
    string str;
    for(int i=0;i<s.size();i++){
        if(s[i]>='X'){
            str.push_back(s[i]);
        }
    }
    // sort(str.begin(),str.end());    //using sort() method

    int n=str.size();
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=0;j<n-i-1;j++){
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
    }
    cout<<str;
}



