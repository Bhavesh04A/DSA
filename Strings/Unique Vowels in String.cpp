class Solution {
  public:
  
    int factorial(int n) {
        int result = 1;
        while (n > 1)
            result *= n--;
        return result;
    }

    int vowelCount(string& s) {
        unordered_map<char, int> vowelCount;
        set<char> vowelsFound;
    
        
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelCount[c]++;
                vowelsFound.insert(c);
            }
        }
    
        
        if (vowelsFound.empty()) return 0;
    
        int waysToChoose = 1;
        for (char v : vowelsFound) {
            waysToChoose *= vowelCount[v];
        }

        int totalPermutations = factorial(vowelsFound.size());
    
        return waysToChoose * totalPermutations;
    }
        
};
