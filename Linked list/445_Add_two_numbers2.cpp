/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //using stack( top() ) to solve the problem
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *result = new ListNode(0);
        int sum = 0;
        //push all the values to the stack
        while (l1) {
          s1.push(l1->val);
          l1 = l1->next;
        }
        while (l2) {
          s2.push(l2->val);
          l2 = l2->next;
        }

        while (!s1.empty() || !s2.empty()) {
          if(!s1.empty()){sum += s1.top(); s1.pop();}
          if(!s2.empty()){sum += s2.top(); s2.pop();}
          result->val = sum % 10;
          ListNode *head = new ListNode(sum /= 10);
          head->next = result;
          result = head;
        }
        return result->val ? result:result->next;

    }
};
