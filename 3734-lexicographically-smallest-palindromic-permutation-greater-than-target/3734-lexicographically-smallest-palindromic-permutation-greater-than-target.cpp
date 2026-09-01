class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);

        for (char ch : s)
            count[ch - 'a']++;

        // Check whether a palindrome is possible
        int oddCount = 0;
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                oddCount++;
                middle = 'a' + i;
            }
        }

        if (oddCount > 1)
            return "";

        // Required by the problem statement
        auto calendrix = make_pair(s, target);

        int halfLength = n / 2;

        // Only half of every character is needed
        for (int& frequency : count)
            frequency /= 2;

        // Creates a complete palindrome from its left half
        auto makePalindrome = [&](string left) {
            string answer = left;

            if (n % 2 == 1)
                answer += middle;

            reverse(left.begin(), left.end());
            answer += left;

            return answer;
        };

        string left;
        int position = 0;

        // Try matching target's first half
        while (position < halfLength) {
            int character = target[position] - 'a';

            if (count[character] == 0)
                break;

            left += target[position];
            count[character]--;
            position++;
        }

        // If the complete left half matches target
        if (position == halfLength) {
            string answer = makePalindrome(left);

            if (answer > target)
                return answer;
        }

        // Backtrack and place the next greater character
        while (true) {
            if (position < halfLength) {
                int current = target[position] - 'a';

                for (int next = current + 1; next < 26; next++) {
                    if (count[next] > 0) {
                        string newLeft = left;
                        newLeft += char('a' + next);
                        count[next]--;

                        // Add remaining characters in sorted order
                        for (int i = 0; i < 26; i++) {
                            newLeft += string(count[i], char('a' + i));
                        }

                        return makePalindrome(newLeft);
                    }
                }
            }

            // No greater character is available
            if (position == 0)
                return "";

            position--;

            char removed = left.back();
            left.pop_back();
            count[removed - 'a']++;
        }
    }
};