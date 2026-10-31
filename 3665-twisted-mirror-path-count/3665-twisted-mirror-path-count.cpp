class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // dp[j].first  = dpR
        // dp[j].second = dpD
        vector<pair<long long, long long>> dp(n + 1, {0, 0});

        dp[1] = {1, 1};   // start cell

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    dp[j + 1] = {
                        dp[j + 1].second, // from top -> reflected right
                        dp[j].first       // from left -> reflected down
                    };
                } else {
                    long long ways =
                        (dp[j + 1].second + dp[j].first) % MOD;

                    dp[j + 1] = {ways, ways};
                }
            }
        }

        return (int)dp[n].first;
    }
};