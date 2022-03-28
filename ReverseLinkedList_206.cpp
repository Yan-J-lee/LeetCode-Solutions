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
        ListNode *pre = new ListNode(0);  // create the virtual head node; pre -> val = 0
        ListNode *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode *temp = cur -> next;
            cur -> next = temp -> next;
            temp -> next = pre -> next;
            pre -> next = temp;
        }
        return pre -> next;
    }
};
