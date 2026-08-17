class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int s : stones) cnt[s % 3]++;

        // If count of 0 is even, Alice wins if both cnt[1] and cnt[2] > 0
        // If count of 0 is odd, Alice wins if abs(cnt[1] - cnt[2]) > 2
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};
