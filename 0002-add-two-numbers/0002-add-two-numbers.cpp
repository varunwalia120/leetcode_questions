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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* pointer1 = l1;
        ListNode* pointer2 = l2;

        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (pointer1 != NULL || pointer2 != NULL || carry != 0) {

            int digit1 = (pointer1 != NULL) ? pointer1->val : 0;
            int digit2 = (pointer2 != NULL) ? pointer2->val : 0;

            int sum = digit1 + digit2 + carry;

            int new_digit = sum % 10;
            carry = sum / 10;

            curr->next = new ListNode(new_digit);
            curr = curr->next;

            if (pointer1 != NULL)
                pointer1 = pointer1->next;

            if (pointer2 != NULL)
                pointer2 = pointer2->next;
        }

        return dummy->next;
    }
};