class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n = s.size();

        // Stores the maximum valid substring length
        int best = 0;

        // Try every possible starting position
        for (int start = 0; start < n; start++) {

            // Frequency array for characters
            vector<int> freq(256, 0);

            // Expand the substring from start to end
            for (int end = start; end < n; end++) {

                // Increase frequency of current character
                freq[s[end]]++;

                // If any character appears more than 2 times,
                // this substring is no longer valid
                if (freq[s[end]] > 2) {
                    break;
                }

                // Calculate current substring length
                int length = end - start + 1;

                // Update maximum length
                best = max(best, length);
            }
        }

        return best;
    }
};