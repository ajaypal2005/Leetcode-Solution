/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify edge cases (like empty lists).
        // 'tail' will always point to the last node in the merged list.
        ListNode dummy;
        ListNode* tail = &dummy;

        // Traverse both lists until one becomes empty
        while (list1 != nullptr && list2 != nullptr) {
            // Compare current nodes of both lists
            if (list1->val <= list2->val) {
                // Attach list1's node to merged list
                tail->next = list1;
                // Move list1 pointer forward
                list1 = list1->next;
            } else {
                // Attach list2's node to merged list
                tail->next = list2;
                // Move list2 pointer forward
                list2 = list2->next;
            }
            // Move tail forward to the newly added node
            tail = tail->next;
        }

        // At least one list is now empty.
        // Attach the remaining non-empty list directly.
        if (list1 != nullptr) tail->next = list1;
        else tail->next = list2;

        // Return the merged list starting from dummy.next
        return dummy.next;
    }
};
