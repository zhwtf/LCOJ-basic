//Given a list, rotate the list to the right by k places, where k is non-negative.

'''
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

k can be greater than the length
'''
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL) return head;
        ListNode* ret = head;
        int len = 0;
        while(ret != NULL){
            ret = ret->next;
            len++;
        }
        k = k % len;

        if(k == 0) return head;
        ListNode* f = head;
        ListNode* s = head;
        while(k != 0){
            f = f->next;
            k--;
        }

        while(f->next != NULL){
            f = f->next;
            s = s->next;

        }
        ret = s->next;
        f->next = head;
        s->next = NULL;
        return ret;
    }
};
