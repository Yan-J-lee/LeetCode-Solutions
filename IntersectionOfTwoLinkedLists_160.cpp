// Two Pointers

// Solution 1
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

// Solution 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *p = headA, *q = headB;
        ListNode *temp;
        
        for (temp = headA; temp != NULL; temp = temp -> next) {
            ++lenA;
        }
        for (temp = headB; temp != NULL; temp = temp -> next) {
            ++lenB;
        }
        
        // 指向更长的链表的指针先移动，使两个指针指向两个链表的表尾的长度相等
        int i;
        if (lenA >= lenB) {
            for (i = 0; i < lenA - lenB; ++i) {
                p = p -> next;
            }
        }
        else {
            for (i = 0; i < lenB - lenA; ++i) {
                q = q -> next;
            }
        }
        
        while (p != q) {
            p = p -> next;
            q = q -> next;
        }
        
        return p;
    }
};
