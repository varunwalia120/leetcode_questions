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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        vector<int> ll;
        while(temp != NULL){
            ll.push_back(temp -> val);
            temp = temp -> next;
        }
        int decimal = 0;
        for(int i = 0; i< ll.size();i++){
            decimal = decimal * 2 + ll[i];
        }
        return decimal;
    }
};