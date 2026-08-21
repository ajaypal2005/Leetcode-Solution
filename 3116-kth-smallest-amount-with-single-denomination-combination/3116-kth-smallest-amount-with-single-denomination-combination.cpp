class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Step 1: Remove redundant coins
        sort(coins.begin(), coins.end());
        vector<int> filtered;
        for (int c : coins) {
            bool redundant = false;
            for (int f : filtered) {
                if (c % f == 0) { redundant = true; break; }
            }
            if (!redundant) filtered.push_back(c);
        }

        long long left = filtered[0], right = 1LL * filtered[0] * k, ans = -1;

        auto countUpTo = [&](long long x) {
            long long cnt = 0;
            int n = filtered.size();
            // Inclusion-Exclusion with bitmask
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd(lcm, (long long)filtered[i]);
                        if (lcm > x / (filtered[i] / g)) { overflow = true; break; }
                        lcm = lcm / g * filtered[i];
                    }
                }
                if (!overflow) {
                    int bits = __builtin_popcount(mask);
                    if (bits % 2) cnt += x / lcm;
                    else cnt -= x / lcm;
                }
            }
            return cnt;
        };

        // Step 3: Binary Search
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (countUpTo(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
