// Two Pointers

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if (slow == fast)  // if there is a cycle
                break;
        }
        
        if (fast == NULL || fast -> next == NULL)
            return NULL;  // no cycle in the list
        
        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
    }
};
