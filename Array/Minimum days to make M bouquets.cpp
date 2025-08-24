class Solution {
  public:
  
    bool canMake(vector<int>& arr, int m, int k, int day) {
        int count = 0;     
        int bouquets = 0;  

        for (int bloomDay : arr) {
            if (bloomDay <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0; 
                }
            } else {
                count = 0;  
            }
        }
        return bouquets >= m;
    }
    
    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long totalNeeded = 1LL * m * k;
        if (totalNeeded > arr.size()) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        return ans;
        
    }
};
