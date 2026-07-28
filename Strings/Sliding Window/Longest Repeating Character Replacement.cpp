class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;    
        int maxFreq = 0;  
        int maxLen = 0;

        int l=0, r=0;
        while(r< n){
            freq[s[r]]++;
            maxFreq= max( maxFreq, freq[s[r]]);
            if((r-l+1)- maxFreq> k){
                freq[s[l]]--;
                maxFreq=0;
                l++;
            }
            if((r-l+1)- maxFreq<=k){
                maxLen= max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
