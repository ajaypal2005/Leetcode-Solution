class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        vector<long long> cnt(31, 0);

        // Count how many times each bit is present
        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (num & (1LL << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Build k numbers greedily
        while (k--) {
            long long cur = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (cnt[bit] > 0) {
                    cur |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + (cur % MOD) * (cur % MOD)) % MOD;
        }

        return (int)ans;
    }
};