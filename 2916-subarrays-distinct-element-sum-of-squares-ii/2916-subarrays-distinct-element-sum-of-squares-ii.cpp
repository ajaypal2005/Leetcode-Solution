class Solution {
    static constexpr int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> st;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1;

        st[p].sq += 2LL * v * st[p].sum + len * v * v;
        st[p].sum += len * v;
        st[p].lazy += v;
    }

    void push(int p, int l, int r) {
        if (!st[p].lazy) return;

        int m = (l + r) >> 1;

        apply(p << 1, l, m, st[p].lazy);
        apply(p << 1 | 1, m + 1, r, st[p].lazy);

        st[p].lazy = 0;
    }

    void update(int p, int l, int r,
                int L, int R, long long v) {

        if (R < l || r < L) return;

        if (L <= l && r <= R) {
            apply(p, l, r, v);
            return;
        }

        push(p, l, r);

        int m = (l + r) >> 1;

        update(p << 1, l, m, L, R, v);
        update(p << 1 | 1, m + 1, r, L, R, v);

        st[p].sum =
            st[p << 1].sum + st[p << 1 | 1].sum;

        st[p].sq =
            st[p << 1].sq + st[p << 1 | 1].sq;
    }

public:
    int sumCounts(vector<int>& nums) {

        int n = nums.size();

        st.resize(4 * n);

        unordered_map<int,int> last;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int p = -1;

            if (last.count(nums[i]))
                p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i, 1);

            last[nums[i]] = i;

            ans = (ans + st[1].sq) % MOD;
        }

        return ans;
    }
};