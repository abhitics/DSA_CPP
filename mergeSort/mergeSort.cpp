#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& a,vector<int>& b,vector<int>& v){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) v[k++]=a[i++];   //that condition maintain its stability that's why merge sort is stable
        else v[k++]=b[j++];
    }
    while(j<b.size()){
            v[k++]=b[j++];
    }
    while(i<a.size()){
            v[k++]=a[i++];
    }
}
void mergeSort(vector<int>& v,int n){
    if(n==1) return;
    int n1=n/2;
    int n2=n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[n1+i];
    }
    mergeSort(a,n1);
    mergeSort(b,n2);
    merge(a,b,v);
    //till now space complexity would be nlog(n) but it can be improved by clear the extra space when it is used
    a.clear();
    b.clear();
}
int main() {
    int a[]={7,9,3,90,12,4};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int>v(a,a+n);
    mergeSort(v,n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}