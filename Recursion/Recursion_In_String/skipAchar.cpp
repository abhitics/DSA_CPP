#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<string>
using namespace std;
void skipA(string s,string str){
    char c=str[0];
    if(str.size()==0){
        cout<<s; 
        return ;
    } 
    if(c!='a' &&c!='A')   skipA(s+c,str.substr(1));
    else skipA(s,str.substr(1));
    
}
int main(){
   string str="Abhishek Tiwari";
   skipA("",str);
}