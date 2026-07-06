class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }

private:
    ListNode* helper(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0)
            return nullptr;

        int sum = carry;
        if (l1 != nullptr) sum += l1->val;
        if (l2 != nullptr) sum += l2->val;

        ListNode* node = new ListNode(sum % 10);
        node->next = helper(
            (l1 != nullptr ? l1->next : nullptr),
            (l2 != nullptr ? l2->next : nullptr),
            sum / 10
        );

        return node;
    }
};
