class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Prevent nums[0] access when the vector is empty.
        if (n == 0) {
            return 0;
        }

        // Store all elements for fast searching.
        unordered_set<int> elements(nums.begin(), nums.end());

        // Begin with the first element of the sequential prefix
        int total = nums[0];

        // Must start from 1 because we access nums[i - 1].
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }

            total += nums[i];
        }

        // Find the smallest integer greater than or equal to
        // total that is not present in nums.
        while (elements.find(total) != elements.end()) {
            total++;
        }

        return total;
    }
};