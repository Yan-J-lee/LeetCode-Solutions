// C++ Recursion
class Solution {
private:
    ListNode *left;
    
    bool traverse(ListNode *right) {
        // base case
        if (right == NULL)
            return true;
        
        bool res = traverse(right -> next);
        res = res && (left -> val == right -> val);
        left = left -> next;
        return res;
    }
public:
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
};

// Two Pointers + Iteration
class Solution {
private:
    ListNode * reverse(ListNode *head) {
        ListNode *pre = NULL, *cur = head, *nxt = head;
        while (cur != NULL) {
            nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        // locate the middle node of the list by two pointers
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if (fast != NULL)
            slow = slow -> next;
        
        // two pointers
        ListNode *left = head, *right = reverse(slow);
        while (right != NULL) {
            if (left -> val != right -> val)
                return false;
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
};

// Python
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        new_head = []
        while head:
            new_head += [head.val]
            head = head.next
        return new_head == new_head[::-1]
