// Tips: use data structure min-heap for priority queue to solve this problem

struct compare {
    bool operator() (const ListNode * l, const ListNode * r) {
        return l -> val > r -> val;
    }
};

class Solution {
    ListNode * mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        
        ListNode *head = new ListNode(NULL);  // create the head node
        ListNode *p = head;  // traversal pointer
        
        // construct the min-heap for priority queue
        priority_queue <ListNode *, vector<ListNode *>, compare> pq;
        for (ListNode *node : lists) {
            pq.push(node);
        }
        
        while (!pq.empty()) {
            ListNode *Node = pq.top();
            pq.pop();
            p -> next = Node;
            if (Node -> next != NULL) {
                pq.push(Node -> next);
            }
            p = p -> next;
        }
        return head;
    }
};
