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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        ListNode* ptr = head;

        head = head->next;
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        temp->next = ptr;
        ListNode* pre = ptr;
        ptr = ptr->next;
        while(ptr && ptr->next){
            ListNode* temp = ptr->next;
            ptr->next = temp->next;
            temp->next = ptr;
            pre->next = temp;
            pre = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};

// Simple recursive Solution
public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newhd = head.next;
        head.next = swapPairs(newhd.next);
        newhd.next = head;
        return newhd;
}
