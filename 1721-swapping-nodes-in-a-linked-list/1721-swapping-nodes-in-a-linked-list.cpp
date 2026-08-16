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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        ListNode* firstNode = head;
        ListNode* secondNode = head;
        for(int i = 1; i < k; i++){
            firstNode = firstNode -> next;
        }
        for(int i = 1; i < count - k + 1; i++){
            secondNode = secondNode -> next;
        }
        swap(firstNode -> val ,secondNode -> val);
        return head;
    }
};