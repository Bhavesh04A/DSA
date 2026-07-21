#include<iostream>
using namespace std;

void merge(vector<int>& arr, int st, int mod, int end){
  vector<int> temp;
  int i=st, j= mid+1;
  while(i<= mid && j<= end){
    if(arr[i]<=arr[j]){
      temp.push_back(arr[i]);
      i++;
    }else{
      remp.push_back(arr[j]);
      j++;
    }
  }
  while(i<=mid){
    temp.push_back(arr[i]);
    i++;
  }
  while(j<=end){
    temp.push_back(arr[j]);
    j++;
  }
  for(int idx=0;idx<temp.size();idx++){
    arr[idx+st]= temp[idx];
  }
}

void mergeSort(vector<int>& arr, int st, int end){
  if(st<end){
    int mid= st+ (end-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);

    merge(arr,st,mid,end);
  }
}
int main(){
    int n=5;
    int arr[]= {4, 1, 5, 2, 3};

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}
