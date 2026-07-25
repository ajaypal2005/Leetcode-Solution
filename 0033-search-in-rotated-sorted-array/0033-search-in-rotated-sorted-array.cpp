class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            //finding mid of array
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[i]) {
                // for target value is smaller then mid value
                if (nums[i] <= target && target <= nums[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }

            }
            // for target value is grater then mid
            else {
                if (nums[mid] <= target && target <= nums[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};