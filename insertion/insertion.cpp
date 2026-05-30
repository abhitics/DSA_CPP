#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int arr[5] = {9,5,3,10,5};
    int brr[5];
    for(int i=0;i<5;i++){
        brr[i]=arr[i];
    }
    int n=5;
    for(int i=0;i<n-1;i++){
        int min=INT_MAX;
        int mindx=-1;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                mindx=j;
            }
        }

    }

}