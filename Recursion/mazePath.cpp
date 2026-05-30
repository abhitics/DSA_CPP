#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int maze(int a,int b){
    if(a==0 && b==0)    return 1;
    if(a<0 || b<0)      return 0;
    int rig=maze(a,b-1);
    int down=maze(a-1,b);
    return rig + down ;
}

int main(){
    int a,b;
    cout<<"Enter the destiantion(a,b) if you can go only right and down : ";
    cin>>a>>b;
    cout<<maze(a,b);
    return 0;
}