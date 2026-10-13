class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        // Process each token from left to right.
        for (const string& str : tokens) {
            // If the token is an operator, evaluate the operation
            // using the top two operands from the stack.
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                // The first popped value is the right operand.
                int top1 = st.top();
                st.pop();
                // The second popped value is the left operand.
                int top2 = st.top();
                st.pop();
                int res = 0;
                // Apply the operator in the correct operand order.
                if (str == "+") {
                    res = top2 + top1;
                } else if (str == "-") {
                    res = top2 - top1;
                } else if (str == "*") {
                    res = top2 * top1;
                } else if (str == "/") {
                    // Integer division truncates toward zero.
                    res = top2 / top1;
                }
                // Push the result back for subsequent operations.
                st.push(res);
            } else {
                // Convert the operand string to an integer
                // and push it onto the stack.
                st.push(stoi(str));
            }
        }
        // A valid RPN expression leaves its final result on top.
        return st.top();
    }
};