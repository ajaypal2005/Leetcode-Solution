class Solution {
public:
    int myAtoi(string s) {

        // If the string is empty, return 0
        if (s.empty()) {
            return 0;
        }

        int i = 0;
        int n = s.length();

        // Step 1: Skip all leading spaces
        // Example: "   42" -> move i until it reaches '4'
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If the string contains only spaces, return 0
        if (i == n) {
            return 0;
        }

        // Step 2: Check whether the number is positive or negative
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }

            i++;
        }

        // This variable stores the converted number
        long long res = 0;

        // Step 3: Read digits one by one
        while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {

            // Convert character digit into integer
            // Example: '7' - '0' = 7
            int digit = s[i] - '0';

            // Add the new digit to the result
            // Example: res = 42, digit = 5
            // New result = 42 * 10 + 5 = 425
            res = res * 10 + digit;

            // If the number becomes smaller than INT_MIN,
            // return the minimum 32-bit integer value
            if (sign * res <= INT_MIN) {
                return INT_MIN;
            }

            // If the number becomes greater than INT_MAX,
            // return the maximum 32-bit integer value
            if (sign * res >= INT_MAX) {
                return INT_MAX;
            }

            // Move to the next character
            i++;
        }

        // Step 4: Apply the sign and return the final number
        return static_cast<int>(res * sign);
    }
};