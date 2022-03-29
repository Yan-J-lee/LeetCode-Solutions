// Recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode *new_head = reverseList(head -> next);  // 反转开始节点之后的所有节点的指针指向
        head -> next -> next = head;  // 将递归后反转的链表的末尾节点指向原来的开始节点
        head -> next = NULL;  // 将原来的开始节点（新的尾节点的指针域置为NULL）
        
        return new_head;
    }
};

// Iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *nxt = head;
        while (cur) {
            nxt = cur -> next;
            cur -> next = pre;  // reverse the direction of the pointer cur
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
