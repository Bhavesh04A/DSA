class Solution {
  public:
    vector<string> findExpr(string &s, int target) {
        vector<string> result;
        string path;
        backtrack(s, target, 0, 0, 0, path, result);
        sort(result.begin(), result.end());  
        return result;
    }

  private:
    void backtrack(const string &num, long target, int pos,
                   long eval, long multed, string path,
                   vector<string> &result) {
        if (pos == num.size()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = pos; i < (int)num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;

            string curStr = num.substr(pos, i - pos + 1);
            long cur = stol(curStr);

            if (pos == 0) {
                backtrack(num, target, i + 1, cur, cur, curStr, result);
            } else {
                // '+'
                backtrack(num, target, i + 1, eval + cur, cur, path + "+" + curStr, result);

                // '-'
                backtrack(num, target, i + 1, eval - cur, -cur, path + "-" + curStr, result);

                // '*'
                backtrack(num, target, i + 1, eval - multed + multed * cur, multed * cur,
                          path + "*" + curStr, result);
            }
        }
    }
};

