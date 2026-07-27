class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int res=0, l=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]-'a']++;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                res+= (s.length() - r);
                freq[s[l]-'a']--;
                l++;
            }
        }
        return res;
    }
};
