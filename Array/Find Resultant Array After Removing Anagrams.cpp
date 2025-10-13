class Solution {
public:
    bool isAnagram(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        string s1 = a, s2 = b;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
         vector<string> result;
        for (const string &word : words) {
            if (!result.empty() && isAnagram(result.back(), word)) {
                continue;
            } else {
                result.push_back(word);
            }
        }
        return result;
    }
};
