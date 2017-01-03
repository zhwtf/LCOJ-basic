/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* dum = head;
        ListNode* cur = head->next;
        while (cur){
            if (cur->val != head->val){
                head->next->val = cur->val;
                head = head->next;
            }
            cur = cur->next;
        }
        head->next = NULL;
        return dum;
    }
};
