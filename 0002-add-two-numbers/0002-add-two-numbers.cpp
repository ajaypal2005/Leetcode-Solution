class Solution {
public:
    // Main function that starts the recursive addition of two linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);  // Begin recursion with carry = 0
    }

private:
    // Recursive helper function to process each digit and carry
    ListNode* helper(ListNode* l1, ListNode* l2, int carry) {
        // Base case: if both lists are empty and no carry remains, stop recursion
        if (l1 == nullptr && l2 == nullptr && carry == 0)
            return nullptr;

        // Compute sum of current digits plus carry
        int sum = carry;
        if (l1 != nullptr) sum += l1->val;  // Add l1's digit if available
        if (l2 != nullptr) sum += l2->val;  // Add l2's digit if available

        // Create a new node with the digit part of sum (mod 10)
        ListNode* node = new ListNode(sum % 10);

        // Recursively compute the next node:
        // - Move to next of l1 if it exists
        // - Move to next of l2 if it exists
        // - Pass the new carry (sum / 10)
        node->next = helper(
            (l1 != nullptr ? l1->next : nullptr),
            (l2 != nullptr ? l2->next : nullptr),
            sum / 10
        );

        // Return the constructed node (current digit + link to next)
        return node;
    }
};
