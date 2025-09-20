class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
    
        int low = 1, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool ok = false;
    
            deque<int> dq;
            for (int i = 0; i < n; i++) {
                while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
                dq.push_back(i);
    
                if (dq.front() <= i - mid) dq.pop_front();
    
                if (i >= mid - 1 && arr[dq.front()] <= mid) {
                    ok = true;
                    break;
                }
            }
    
            if (ok) {
                ans = mid;      
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        return ans;
        
    }
};
