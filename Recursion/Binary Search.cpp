class Solution {
public:

int binSearch(vector<int> arr, int tar, int st, int end){
  if(st<= end){
    int mid= st+ (end-st)/2;

    if(mid== tar) return mid;
    else if(mid<=tar){
      return binSearch(arr, tar, mid+1, end);
    }else{
      return binSearch(arr, tar, st, mid-1);
    }
  }
  return -1;

  int Search(vector<int> arr, int tar){
    return binSearch(arr, tar, 0, arr.size()-1);
  }
};
