class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> freqP(256, 0), freqS(256, 0);
        for (char c : p) freqP[c]++;
    
        int count = 0, start = 0, minLen = INT_MAX, startIdx = -1;
        for (int end = 0; end < s.size(); end++) {
            freqS[s[end]]++;
    
            // if character matches requirement
            if (freqP[s[end]] != 0 && freqS[s[end]] <= freqP[s[end]]) {
                count++;
            }
    
            // if all characters matched
            if (count == p.size()) {
                // shrink window from left
                while (freqP[s[start]] == 0 || freqS[s[start]] > freqP[s[start]]) {
                    if (freqS[s[start]] > freqP[s[start]]) 
                        freqS[s[start]]--;
                    start++;
                }
    
                int windowLen = end - start + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIdx = start;
                }
            }
        }
    
        if (startIdx == -1) return "";
        return s.substr(startIdx, minLen);
        
    }
};
