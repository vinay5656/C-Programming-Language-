// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
int calmax(int *arr,int n,int a){
    for(int i=0;i<n;i++){
        arr[i] = abs(arr[i]-a);
    }
    sort(arr, arr+n);
    return arr[n-1]+arr[n-2];
}
int main() {
    // Write C++ code here
    int n;
    int a;
    cin>>n;
    cin>>a
    
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int max = calmax(arr,n,a);
    cout<<max;
    return 0;
}
