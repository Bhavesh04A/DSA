class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n= s.length();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;

        }
        
        int tarFreq= 0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                tarFreq= freq[i];
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0 && freq[i]!= tarFreq){
                return false;
            }
        }
        return true;
    }
};
