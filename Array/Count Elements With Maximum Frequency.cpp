class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        // Count total elements having maximum frequency
        int result = 0;
        for (auto& [key, value] : freq) {
            if (value == maxFreq) {
                result += value;
            }
        }

        return result;
    }
};
