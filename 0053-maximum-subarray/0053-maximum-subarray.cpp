class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize variables:
        // bestending → maximum subarray sum ending at the current index
        // ans → overall maximum subarray sum found so far
        int bestending = nums[0];
        int ans = nums[0];

        // Traverse the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Two choices:
            // 1. Extend the previous subarray (bestending + nums[i])
            // 2. Start a new subarray from current element (nums[i])
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            // Pick the better option for subarray ending at index i
            bestending = max(v1, v2);

            // Update the overall maximum subarray sum
            ans = max(ans, bestending);
        }

        // Return the maximum subarray sum found
        return ans;
    }
};
