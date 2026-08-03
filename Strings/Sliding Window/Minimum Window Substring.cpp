class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.length(), m= t.length();
        unordered_map<char, int> freq;

        for(char c: t){
            freq[c]++;
        }
        int l=0, r=0, count=0, minLen= INT_MAX, sIdx=0;
        while(r<n){
            if(freq[s[r]]>0){
                count++;
            }
            freq[s[r]]--;

            while(count==m){
                if((r-l+1)<minLen){
                    minLen= r-l+1;
                    sIdx= l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return minLen== INT_MAX ? "": s.substr(sIdx, minLen);
    }
};
