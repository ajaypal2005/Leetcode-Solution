class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,int need2) {

        long long common = min(need1, need2);

        long long ans = common * 1LL * min(costBoth, cost1 + cost2);

        long long rem1 = need1 - common;
        long long rem2 = need2 - common;

        ans += rem1 * 1LL * min(cost1, costBoth);
        ans += rem2 * 1LL * min(cost2, costBoth);

        return ans;
    }
};