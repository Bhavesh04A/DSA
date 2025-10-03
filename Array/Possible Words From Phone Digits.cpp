class Solution {
  public:
    void solve(int index, string current, vector<int>& arr, vector<string>& result, vector<string>& mapping) {
        if (index == arr.size()) {
            result.push_back(current);
            return;
        }
    
        int digit = arr[index];
    
        if (digit == 0 || digit == 1) {
            solve(index + 1, current, arr, result, mapping);
            return;
        }
    
        string letters = mapping[digit];
        for (char c : letters) {
            solve(index + 1, current + c, arr, result, mapping);
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
    
        vector<string> result;
        solve(0, "", arr, result, mapping);
        return result;

        
    }
};
