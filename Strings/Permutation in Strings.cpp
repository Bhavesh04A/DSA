#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
        bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;

        int freq1[26] = {0};  
        int freq2[26] = {0};  

        for (int i = 0; i < len1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for (int i = 0; i <= len2 - len1; i++) {
            if (i > 0) {
                freq2[s2[i - 1] - 'a']--;
                freq2[s2[i + len1 - 1] - 'a']++;
            }

           
            if (isFreqSame(freq1, freq2)) return true;
        }

        return false;
    }
};


int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (sol.checkInclusion(s1, s2)) {
        cout << "True\n";  
    } else {
        cout << "False\n";
    }

    return 0;
}
