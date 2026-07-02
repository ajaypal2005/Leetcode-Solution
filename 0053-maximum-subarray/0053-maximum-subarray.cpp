class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size(); 
        int maxi = INT_MIN; // Stores the maximum subarray sum found so far
        int sum = 0;        // Running sum of the current subarray

        // Traverse the array
        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];       // Add current element to the running sum
            maxi = max(maxi, sum);     // Update maximum if current sum is greater

            // If running sum becomes negative, reset it to 0
            // (because continuing with a negative sum will only reduce future totals)
            if (sum < 0)
                sum = 0;
        }

        // Return the maximum subarray sum found
        return maxi;
    }
};
