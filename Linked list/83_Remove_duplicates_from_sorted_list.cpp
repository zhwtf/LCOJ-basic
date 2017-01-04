/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /**
 First iteration to negate values at position whose equal to values appear in array.
 Second iteration to collect all position whose value is positive,
 which are the missing values. Complexity is O(n) Time and O(1) space.
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
