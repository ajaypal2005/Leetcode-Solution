class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());   // Step 1: Sort the array to handle duplicates easily
        vector<vector<int>> res;          // Result vector to store quadruplets
        int n = nums.size();

        // Step 2: First loop for the first element
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Second loop for the second element
            for (int j = i + 1; j < n; j++) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 4: Two-pointer approach for the remaining two elements
                int left = j + 1, right = n - 1;

                while (left < right) {
                    // Use long long to avoid integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // Found a valid quadruplet
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicates for the third element
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        // Skip duplicates for the fourth element
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum < target) {
                        // If sum is too small, move left pointer to increase sum
                        left++;
                    }
                    else {
                        // If sum is too large, move right pointer to decrease sum
                        right--;
                    }
                }
            }
        }
        return res;   // Return all unique quadruplets
    }
};
