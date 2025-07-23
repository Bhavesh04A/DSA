class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
    
        for (int i = 0; i < n; ++i) {
            long long contribution = (long long)(i + 1) * (n - i) * arr[i];
            totalSum += contribution;
        }
    
        return static_cast<int>(totalSum);
    }
};
