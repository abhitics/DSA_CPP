#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void hanoi(int n,char s,char a,char d){
    if(n==0) return;
    hanoi(n-1,s,d,a);
    cout<<s<<"->"<<d<<endl;
    hanoi(n-1,a,s,d);
}

int main(){
    int a;
    cout<<"Enter the number of disks: ";
    cin>>a;
    hanoi(a,'A','B','C');
    return 0;
}