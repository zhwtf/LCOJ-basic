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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //using two pointers
        if(head->next == NULL)return NULL;
        auto dum = head;
        auto slow = head;
        auto fast = head;

        while(n > 0){
            fast = fast->next;
            n--;
        }

        while(fast && fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == NULL && slow == head) return slow->next;

        slow->next = slow->next->next;
        return dum;
    }
};
