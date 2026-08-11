class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size(); // Get the length of the input string
        stack<char> st;   // Stack to store characters
        string res;       // Result string to build the final answer

        // Traverse through each character of the string
        for (int i = 0; i < n; i++) {
            if (st.empty()) { // If stack is empty, push the current character
                st.push(s[i]);
                continue;
            }

            if (st.top() == s[i]) { // If current char is same as top of stack
                st.pop();           // Remove the duplicate (pop from stack)
                continue;
            }

            st.push(s[i]); // Otherwise, push the current character
        }

        // Pop all characters from stack and build the result string
        while (!st.empty()) {
            res.push_back(st.top()); // Add top character to result
            st.pop();                // Remove it from stack
        }

        // Reverse the result because stack gives characters in reverse order
        reverse(res.begin(), res.end());

        return res; // Return the final string without duplicates
    }
};
