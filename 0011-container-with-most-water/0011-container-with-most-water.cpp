class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;                 // Variable to store the maximum area found
        int left = 0;                    // Left pointer starts at the beginning
        int right = height.size() - 1;   // Right pointer starts at the end

        // Use two-pointer approach to maximize area
        while (left < right) {
            // Calculate area formed between left and right lines
            // Width = (right - left)
            // Height = min(height[left], height[right]) because water is limited by the shorter line
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            // Move the pointer pointing to the shorter line inward
            // This is because moving the taller line won't help increase area (height is limited by shorter line)
            if (height[left] < height[right]) {
                left++;   // Move left pointer forward
            } else {
                right--;  // Move right pointer backward
            }
        }

        return maxArea;   // Return the maximum area found
    }
};
