class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();                 // Total number of elements in the array
        int low = 0;                         // Left pointer of the sliding window
        int sum = 0;                         // Current sum of the window
        int res = numeric_limits<int>::max();// Store the minimum length found so far

        // Expand the window by moving the right pointer
        for (int high = 0; high < n; high++) {
            sum += nums[high];               // Add current element to the window sum

            // Shrink the window from the left while sum >= target
            while (sum >= target) {
                // Update the minimum length of subarray
                res = min(res, high - low + 1);

                // Remove the leftmost element and move left pointer forward
                sum -= nums[low];
                low++;
            }
        }

        // If no valid subarray was found, return 0
        return (res == numeric_limits<int>::max()) ? 0 : res;
    }
};
