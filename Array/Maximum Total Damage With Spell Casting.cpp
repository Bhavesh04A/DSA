class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> damageSum;
        for (int p : power) {
            damageSum[p] += p; 
        }

        vector<long long> unique;
        unique.reserve(damageSum.size());
        for (auto &it : damageSum) {
            unique.push_back(it.first);
        }
        sort(unique.begin(), unique.end());

        int n = unique.size();
        if (n == 0) return 0;
        if (n == 1) return damageSum[unique[0]];

        vector<long long> dp(n, 0);
        dp[0] = damageSum[unique[0]];

        if (unique[1] - unique[0] <= 2)
            dp[1] = max(dp[0], damageSum[unique[1]]);
        else
            dp[1] = dp[0] + damageSum[unique[1]];

        for (int i = 2; i < n; i++) {
            if (unique[i] - unique[i-1] <= 2) {
                dp[i] = max(dp[i-1], dp[i-2] + damageSum[unique[i]]);
            } else {
                dp[i] = dp[i-1] + damageSum[unique[i]];
            }
        }

        return dp[n-1];
    }
};
