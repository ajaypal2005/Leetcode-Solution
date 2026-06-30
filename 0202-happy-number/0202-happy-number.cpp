class Solution {
public:
    // Helper function to compute the sum of squares of digits of n
    int getNext(int n) {
        int total = 0;
        while (n > 0) {
            int d = n % 10;      // extract last digit
            n /= 10;             // remove last digit
            total += d * d;      // add square of digit to total
        }
        return total;            // return sum of squares
    }

    bool isHappy(int n) {
        // Initialize slow and fast pointers
        int slow = n;            // moves one step at a time
        int fast = getNext(n);   // moves two steps at a time

        // Loop until fast reaches 1 (happy number) or slow meets fast (cycle detected)
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);            // move slow one step
            fast = getNext(getNext(fast));   // move fast two steps
        }

        // If fast reached 1, it's a happy number; otherwise, stuck in a cycle
        return fast == 1;
    }
};
