class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        // Stores the frequency of each number
        // inside the current sliding window
        unordered_map<int, int> frequency;

        int left = 0;               // Starting index of the window
        int right = 0;              // Ending index of the window
        int n = nums.size();
        int maxLength = 0;          // Maximum valid subarray length

        // Expand the window by moving the right pointer
        while (right < n) {

            // Add the current number to the window
            frequency[nums[right]]++;

            // If the current number appears more than k times,
            // shrink the window from the left
            while (frequency[nums[right]] > k) {

                // Remove the leftmost number from the window
                frequency[nums[left]]--;

                // Move the left pointer forward
                left++;
            }

            // The current window is now valid.
            // Calculate its length and update the maximum.
            maxLength = max(maxLength, right - left + 1);

            // Move the right pointer to process the next element
            right++;
        }

        return maxLength;
    }
};