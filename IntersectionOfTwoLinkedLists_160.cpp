// Two Pointers

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            if (p != NULL) {
                p = p -> next;
            }
            else {
                p = headB;
            }
            if (q != NULL) {
                q = q -> next;
            }
            else {
                q = headA;
            }
        }
        return p;
    }
};
