class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQuestions = 0, rightQuestions = 0;

        // Calculate digit sums and count '?' in both halves
        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < half) {
                    leftQuestions++;
                } else {
                    rightQuestions++;
                }
            } else {
                if (i < half) {
                    leftSum += num[i] - '0';
                } else {
                    rightSum += num[i] - '0';
                }
            }
        }

        int totalQuestions = leftQuestions + rightQuestions;

        // Alice gets the last move, so she can force unequal sums
        if (totalQuestions % 2 != 0) {
            return true;
        }

        int sumDifference = leftSum - rightSum;
        int questionDifference = rightQuestions - leftQuestions;

        // Bob wins only when he can make both halves equal.
        // Multiplication by 2 avoids floating-point division.
        return 2 * sumDifference != 9 * questionDifference;
    }
};