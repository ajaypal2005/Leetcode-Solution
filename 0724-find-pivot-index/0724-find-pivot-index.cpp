class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Step 1: Calculate the total sum of the array
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // Step 2: Initialize leftSum to track sum of elements before current index
        int leftSum = 0;

        // Step 3: Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            // Right sum = total sum - left sum - current element
            int rightSum = totalSum - leftSum - nums[i];

            // Step 4: Check if left sum equals right sum
            if (leftSum == rightSum) return i;  // Found pivot index

            // Step 5: Update left sum by adding current element
            leftSum += nums[i];
        }

        // Step 6: If no pivot index found, return -1
        return -1;
    }
};
