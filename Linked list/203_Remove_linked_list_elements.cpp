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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)return NULL;
        while(head && head->val == val){
            head = head->next;
        }
        if (head == NULL)return NULL;
        ListNode* cur = head->next;
        ListNode* dum = head;
        while(cur){
            if (cur->val != val){
                head->next = cur;
                head = head->next;
            }
            cur = cur->next;
        }
        head->next = NULL;
        return dum;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pseudo_head = new ListNode(0);
        pseudo_head->next = head;
        ListNode *cur = pseudo_head;
        while(cur){
            if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
            else    cur = cur->next;
        }
        return pseudo_head->next;
    }
};
