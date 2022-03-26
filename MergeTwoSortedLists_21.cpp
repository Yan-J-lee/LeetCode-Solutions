class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *list = new ListNode(NULL);  // create the head node of the merged linked list
        ListNode *r = list;  // tail pointer: always points to the tail of the merged linked list
        
        while (p != NULL && q != NULL) {
            if (p -> val <= q -> val) {
                r -> next = p;
                p = p -> next;
            }
            else {
                r -> next = q;
                q = q -> next;
            }
            r = r -> next;
        }
        if (p != NULL) {
            r -> next = p;
        }
        if (q != NULL) {
            r -> next = q;
        }
        return list -> next;
    }
};
