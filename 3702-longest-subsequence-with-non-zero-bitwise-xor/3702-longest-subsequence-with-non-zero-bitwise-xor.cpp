class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();

        // Stores XOR of all elements
        int x = 0;

        // Checks whether array contains
        // at least one non-zero number
        bool nonZero = false;

        // Calculate XOR of complete array
        for (int num : nums) {

            x = x ^ num;

            // If we find any non-zero number
            if (num != 0) {
                nonZero = true;
            }
        }

        // If XOR of complete array is already non-zero,
        // we can take all elements
        if (x != 0) {
            return n;
        }

        // If XOR is 0 but there is at least one
        // non-zero element, remove one suitable element.
        // Then we can get a non-zero XOR.
        if (nonZero) {
            return n - 1;
        }

        // If all numbers are 0,
        // every subsequence will have XOR = 0
        return 0;
    }
};