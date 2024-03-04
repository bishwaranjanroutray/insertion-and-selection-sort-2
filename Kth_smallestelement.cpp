// Given an integer array and an integer k where k<=size of array, We need to return the kth
// smallest element of the array.

#include<iostream>
using namespace std;

int small(int arr[],int s,int k){

    // selection sort
    for(int i=0;i<s-1;i++){
        int idx=i;
        for(int j=i+1;j<s;j++){
            if(arr[j]<arr[idx]){
                idx=j;
            }
        }
        swap(arr[idx],arr[i]);
    }

    return arr[k-1];
}

int main(){
    int arr[5]={4,5,7,6,1};
    cout<<small(arr,5,5);
}