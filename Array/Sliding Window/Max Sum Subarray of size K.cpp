class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1;
        
        int l=0, sum=0, maxSum=INT_MIN, len=0;
        
        for(int r=0;r<n;r++){
            sum+= arr[r];
            len++;
            
            if(len>k){
                sum-=arr[l];
                l++;
                len--;
            }
            if(len== k){
                maxSum= max(sum, maxSum);
            }
        }
        return maxSum;
        
    }
};
