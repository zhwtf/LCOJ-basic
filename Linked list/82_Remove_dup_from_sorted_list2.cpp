//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

//1. recursive method
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;

        int val = head->val;
        ListNode* p = head->next;

        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        }
        else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};
