class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Stores whether a character is currently present
        // in the sliding window (ASCII characters only).
        vector<bool> arr(128, false);

        int maxLen = 0; // Stores the maximum length found so far.
        int l = 0;      // Left pointer of the sliding window.
        int r = 0;      // Right pointer of the sliding window.

        // Expand the window until the right pointer reaches the end.
        while (r < s.size()) {

            // If the current character is not in the window,
            // we can safely include it.
            if (!arr[s[r]]) {
                arr[s[r]] = true; // Mark the character as present.

                // Update the maximum window size.
                maxLen = max(maxLen, r - l + 1);

                // Expand the window by moving the right pointer.
                r++;
            }
            else {
                // Duplicate character found.
                // Remove the leftmost character from the window
                // until the duplicate is removed.
                arr[s[l]] = false;
                l++;
            }
        }

        // Return the length of the longest substring
        // without repeating characters.
        return maxLen;
    }
};