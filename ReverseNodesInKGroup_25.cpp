class Solution {
private:
  // 此函数实现逆转a到b之间的节点
    ListNode *reverseBetween(ListNode *a, ListNode *b) {
        ListNode *pre = nullptr, *cur = a, *nxt = a;
        while (cur != b) {
            nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 区间[a, b)包含k个待reverse的元素
        ListNode *a, *b;
        a = b = head;
        
        for (int i = 0; i < k; ++i) {
            if (b == NULL) {
                return head;  // base case
            }
            b = b -> next;
        }
        
        ListNode *new_head = reverseBetween(a, b);
        a -> next = reverseKGroup(b, k);
        return new_head;
    }
};
