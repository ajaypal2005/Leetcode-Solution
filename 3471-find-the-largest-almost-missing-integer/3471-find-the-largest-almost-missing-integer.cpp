class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k == n
        // Only one subarray exists, so every number appears
        // in exactly one subarray.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Count frequency of every number
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Case 2: k == 1
        // Every element itself is a subarray.
        // So we need the largest number appearing only once.
        if (k == 1) {
            int ans = -1;

            for (auto& it : freq) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }

            return ans;
        }

        // Case 3: 1 < k < n
        // Only first and last elements can appear
        // in exactly one subarray.

        int ans = -1;

        if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};