class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to keep track of opening brackets

        // Iterate through each character in the string
        for (char cur : s) {
            // If stack is not empty, check the top element
            if (!st.empty()) {
                char last = st.top();  // Get the last pushed bracket

                // If current character forms a valid pair with the last one
                if (isPair(last, cur)) {
                    st.pop();  // Remove the matched opening bracket
                    continue;  // Move to the next character
                }
            }
            // If no match found, push current character onto stack
            st.push(cur);
        }

        // If stack is empty, all brackets were matched correctly
        return st.empty();        
    }

private:
    // Helper function to check if two characters form a valid bracket pair
    bool isPair(char last, char cur) {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }
};
