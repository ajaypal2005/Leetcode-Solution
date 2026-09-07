class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // ending[i] stores the number of distinct subsequences
        // that end with character ('a' + i).
        vector<long long> ending(26, 0);

        long long total = 0;

        for (char ch : s) {
            int index = ch - 'a';

            // Append ch to every existing subsequence.
            // Also count the subsequence containing only ch.
            long long newEnding = (total + 1) % MOD;

            // Remove subsequences previously ending with ch
            // because newEnding replaces them.
            total = (total - ending[index] + newEnding + MOD) % MOD;

            ending[index] = newEnding;
        }

        return static_cast<int>(total);
    }
};