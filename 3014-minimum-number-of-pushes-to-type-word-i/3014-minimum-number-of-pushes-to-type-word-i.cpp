class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Create a frequency array for 26 lowercase letters
        // Each index represents a character 'a' to 'z'
        vector<int> charCount(26, 0);

        // Step 2: Count frequency of each character in the given word
        for(char ch : word) {
            charCount[ch - 'a']++;
        }

        // Step 3: Sort frequencies in descending order
        // This ensures the most frequent characters come first
        sort(charCount.begin(), charCount.end(), greater<int>());

        int minPushCount = 0;

        // Step 4: Calculate minimum pushes
        // Logic: Keyboard has 8 slots per row. 
        // Characters at indices 0–7 cost 1 push, 8–15 cost 2 pushes, etc.
        for(int i = 0; i < 26; i++) {
            // (i / 8 + 1) gives the push cost depending on position
            minPushCount += charCount[i] * (i / 8 + 1);
        }

        // Step 5: Return the total minimum push count
        return minPushCount;
    }
};
