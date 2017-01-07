//Write a program to find the node at which the intersection of two singly linked lists begins.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning,
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1 ? cur1->next:headB;
        cur2 = cur2 ? cur2->next:headA;
    }
    return cur1;
}

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //if there is an intersection, their last nodes must be the same!
        if (headA == NULL || headB == NULL) return NULL;
        if (headA->next == NULL && headB->next == NULL) return headA==headB ? headA:NULL;
        if (headA == headB) return headA;
        auto p1 = headA, p2 = headB;
        int c1, c2;
        while(p1->next != NULL){
            p1 = p1->next;
            c1++;
        }
        while(p2->next != NULL){
            p2 = p2->next;
            c2++;
        }
        if (p2 == p1){

            while((c1-c2) > 0){
                headA = headA->next;
                c1--;
            }


            while((c2-c1) > 0){
                headB = headB->next;
                c2--;
            }


            while(headA != headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;

        }
        return NULL;
     }
};
