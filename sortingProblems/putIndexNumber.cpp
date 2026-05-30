#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={7,3,9,4,1,2};
    int n=6;
    vector<int>brr(arr,arr+n);
    // for(int i=0;i<n;i++){
    //     brr.push_back(arr[i]);    //OR vector<int> brr(arr, arr + n); to copy content of pre-existing array
    //     cout<<arr[i] <<" ";       //vector<int> part(brr.begin() + 2, brr.begin() + 5);  for range copying
    // }
    sort(brr.begin(),brr.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==brr[j])
                arr[i]=j;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i] <<" ";
    }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     int arr[] = {7, 3, 9, 4, 1, 2};
//     int n = 6;

//     vector<int> brr(arr, arr + n);  // copy array
//     sort(brr.begin(), brr.end());   // sorted version

//     // Replace arr[i] with its position (rank)
//     for (int i = 0; i < n; i++) {
//         int rank = lower_bound(brr.begin(), brr.end(), arr[i]) - brr.begin();
//         arr[i] = rank;
//     }

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }


