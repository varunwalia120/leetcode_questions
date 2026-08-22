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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* resultHead = NULL;
        ListNode* resultTail = NULL;
        int sum = 0;

        while (temp != NULL) {
            if (temp->val != 0) {
                sum += temp->val;
            } else if (sum != 0) {
                ListNode* newNode = new ListNode(sum);

                if (resultHead == NULL) {
                    resultHead = newNode;
                    resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }

                sum = 0;
            }

            temp = temp->next;
        }

        return resultHead;
    }
};