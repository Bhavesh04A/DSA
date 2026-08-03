class Solution {
  public:
    int smallestSubstring(string &s) {
        int freq[3] = {0};
        int count = 0;
        int l = 0;
        int ans = INT_MAX;
        
        for(int r=0;r<s.length();r++){
            if(freq[s[r]-'0']==0){
                count++;
            }
            freq[s[r]-'0']++;
            while(count==3){
                ans= min(ans, r-l+1);
                freq[s[l]-'0']--;
                if(freq[s[l]-'0']==0){
                    count--;
                }
                l++;
            }
        }
        return ans==INT_MAX ? -1: ans;
        
    }
};
