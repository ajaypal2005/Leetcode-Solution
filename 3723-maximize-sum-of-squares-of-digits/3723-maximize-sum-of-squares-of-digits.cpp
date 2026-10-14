class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        while (num--) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        if (sum > 0)
            return "";
        return ans;
    }
};