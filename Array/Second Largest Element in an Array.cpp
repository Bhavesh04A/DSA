class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n= arr.size();
        
        int largest=-1, second=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]> largest){
                second= largest;
                largest= arr[i];
            }
            else if(arr[i]> second && arr[i]< largest){
                second= arr[i];
            }
        }
        return second;
    }
};
