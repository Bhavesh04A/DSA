class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flips = 0, currFlips = 0;
        vector<int> isFlipped(n, 0); 
        
        for (int i = 0; i < n; i++) {
            if (i >= k) currFlips ^= isFlipped[i - k];
            
            int effective = arr[i] ^ currFlips;
            
            if (effective == 0) { 
                if (i + k > n) return -1;
                flips++;
                currFlips ^= 1;
                isFlipped[i] = 1;   
            }
        }
        return flips;
    }
};
