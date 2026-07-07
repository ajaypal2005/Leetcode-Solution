class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes because of the '-' sign
        if (x < 0) {
            return false;
        }

        long reverse = 0;   // Variable to store the reversed number
        int xcopy = x;      // Keep a copy of the original number for comparison

        // Reverse the digits of x
        while (x > 0) {
            // Take the last digit of x and add it to reverse
            reverse = (reverse * 10) + (x % 10);
            // Remove the last digit from x
            x /= 10;
        }

        // If the reversed number equals the original, it's a palindrome
        return reverse == xcopy;
    }
};
