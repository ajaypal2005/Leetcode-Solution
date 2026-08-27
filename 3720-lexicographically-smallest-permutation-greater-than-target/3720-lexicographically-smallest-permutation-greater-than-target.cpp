class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        // Store frequency of every character in s
        vector<int> frequency(26, 0);

        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        // Match target's prefix for as long as possible
        int matched = 0;

        while (matched < n) {
            int character = target[matched] - 'a';

            if (frequency[character] == 0) {
                break;
            }

            frequency[character]--;
            matched++;
        }

        /*
         Try changing the rightmost possible position.
         A later change produces a smaller answer.
        */
        for (int position = min(matched, n - 1);
             position >= 0;
             position--) {

            // Restore the character while backtracking
            if (position < matched) {
                frequency[target[position] - 'a']++;
            }

            int currentCharacter = target[position] - 'a';

            // Find the smallest available character greater than target[position]
            for (int nextCharacter = currentCharacter + 1;
                 nextCharacter < 26;
                 nextCharacter++) {

                if (frequency[nextCharacter] > 0) {
                    string answer = target.substr(0, position);

                    // Make this position greater
                    answer.push_back('a' + nextCharacter);
                    frequency[nextCharacter]--;

                    // Add remaining characters in sorted order
                    for (int character = 0; character < 26; character++) {
                        answer.append(
                            frequency[character],
                            char('a' + character)
                        );
                    }

                    return answer;
                }
            }
        }

        // No greater permutation exists
        return "";
    }
};