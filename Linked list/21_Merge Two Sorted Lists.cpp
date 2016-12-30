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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1 == NULL) return l2;
         if(l2 == NULL) return l1;
         //first create a empty pointer used to hold the new combined list
         ListNode *ptr;
         ListNode *dummyhead = ptr;
         while(l1 != NULL && l2 != NULL){
             if (l1->val >= l2->val){
                 ptr->next = l2;
                 l2 = l2->next;
                 ptr = ptr->next;
             }
             else{
                 ptr->next = l1;
                 l1 = l1->next;
                 ptr = ptr->next;
             }
         }
         //look for which list finished first
         ptr->next = l1 ? l1:l2;
         return dummyhead->next;
     }
 };



//14 line clean C++ Solution
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
