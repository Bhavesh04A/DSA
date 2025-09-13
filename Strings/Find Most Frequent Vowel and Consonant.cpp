class Solution {
public:

    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }
        
        int maxVowelFreq = 0, maxConsonantFreq = 0;
        
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        
        for (auto &entry : freq) {
            char ch = entry.first;
            int count = entry.second;
            
            if (isVowel(ch)) {
                maxVowelFreq = max(maxVowelFreq, count);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, count);
            }
        }
        
        return maxVowelFreq + maxConsonantFreq;
    }
};
