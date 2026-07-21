#include<iostream>
using namespace std;

int partition(vector<int>& arr, int st, int end){
  int idx= st-1, pivot= arr[end];
  for(int j=st;j<end;j++){
    if(arr[j]<=pivot){
      idx++;
      swap(arr[j], arr[idx]);
    }
  }
  idx++;
  swap(arr[end],arr[idx]);
  return idx;
}

void quickSort(vector<int>& arr, int st, int end){
  if(st<end){
    int pivotIdx= parition(arr,st,end);

    quickSort(arr,st,pivotIdx-1);
    quickSort(arr,pivotIdx+1, end);
    
  }
}

int main(){
    int n=5;
    int arr[]= {4, 1, 5, 2, 3};

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}
