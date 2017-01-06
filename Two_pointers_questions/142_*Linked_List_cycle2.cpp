//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *slow=head;
        ListNode *fast=head;

        fast = fast->next->next;
        slow = slow->next;
        while (fast != NULL && fast->next != NULL && fast != slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == NULL || fast->next == NULL) return NULL;
        // otherwise it has a cycle. then determine the length of the cycle
        int len;
        do{
            fast = fast->next;
            len++;
        }while(fast != slow);
        slow = head;
        fast = head;
        while(len){
            fast = fast->next;
            len--;
        }
        while (slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
