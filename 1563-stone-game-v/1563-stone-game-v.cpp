class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sum array to quickly calculate subarray sums
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i] + stoneValue[i];

        // dp[i][j] = maximum score Alice can get from subarray stoneValue[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over all possible subarray lengths
        for (int len = 2; len <= n; len++) {
            // For each subarray of length 'len'
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1; // end index of subarray

                // Try splitting at every possible position k
                for (int k = i; k < j; k++) {
                    // Left sum = sum of stones from i..k
                    int left = prefix[k+1] - prefix[i];
                    // Right sum = sum of stones from k+1..j
                    int right = prefix[j+1] - prefix[k+1];

                    // Case 1: Left sum < Right sum → Alice gains left + dp[i][k]
                    if (left < right) 
                        dp[i][j] = max(dp[i][j], left + dp[i][k]);
                    // Case 2: Right sum < Left sum → Alice gains right + dp[k+1][j]
                    else if (left > right) 
                        dp[i][j] = max(dp[i][j], right + dp[k+1][j]);
                    // Case 3: Equal sums → Alice chooses best option
                    else 
                        dp[i][j] = max(dp[i][j], left + max(dp[i][k], dp[k+1][j]));
                }
            }
        }

        // Final answer: maximum score Alice can get from the whole array
        return dp[0][n-1];
    }
};
