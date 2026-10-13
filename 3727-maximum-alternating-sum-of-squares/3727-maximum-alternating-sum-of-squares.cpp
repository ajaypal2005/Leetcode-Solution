class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for (int x : nums) {
            sq.push_back(1LL * x * x);
        }
        sort(sq.begin(), sq.end());
        int n = sq.size();
        int pos = (n + 1) / 2;
        long long sum = 0;
        for (int i = n - pos; i < n; i++) {
            sum += sq[i];
        }

        for (int i = 0; i < n - pos; i++) {
            sum -= sq[i];
        }
        return sum;
    }
};
