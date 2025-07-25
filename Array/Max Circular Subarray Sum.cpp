class Solution {
  public:
    int kadane(const vector<int>& arr) {
        int max_ending_here = arr[0];
        int max_so_far = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            max_ending_here = max(arr[i], max_ending_here + arr[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }

    int min_kadane(const vector<int>& arr) {
        int min_ending_here = arr[0];
        int min_so_far = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            min_ending_here = min(arr[i], min_ending_here + arr[i]);
            min_so_far = min(min_so_far, min_ending_here);
        }
        return min_so_far;
    }
    int maxCircularSum(vector<int> &arr) {
        int max_kadane_sum = kadane(arr);             
        int total_sum = 0;
    
        for (int num : arr)
            total_sum += num;
    
        int min_kadane_sum = min_kadane(arr);        
    
        int max_wrap_sum = total_sum - min_kadane_sum; 
    
        
        if (max_wrap_sum == 0)
            return max_kadane_sum;
    
        return max(max_kadane_sum, max_wrap_sum);
    }
};
