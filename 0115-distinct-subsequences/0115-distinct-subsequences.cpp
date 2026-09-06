class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<unsigned long long> dp(n + 1, 0);

        // Empty target can be formed in one way
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            // Traverse backward to preserve previous-row values
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }

        return static_cast<int>(dp[n]);
    }
};