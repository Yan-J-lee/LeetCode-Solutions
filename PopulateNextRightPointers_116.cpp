/*
Algorithm:
1. connect two nodes with the same parent
2. connect two nodes with different parents
*/

class Solution {
public:
    void connectTwoNodes (Node * &tree1, Node * &tree2) {
        // base case
        if (tree1 == NULL || tree2 == NULL) {
            return;
        }
        
        tree1 -> next = tree2;
        // two nodes with the same parent
        connectTwoNodes(tree1 -> left, tree -> right);
        connectTwoNodes(tree2 -> left, tree2 -> right);
        // two nodes with different parents
        connectTwoNodes(tree1 -> right, tree2 -> left);
    }
    
    Node * connect(Node *root) {
        if (root == NULL) {
            return NULL;
        }
        connectTwoNodes(root -> left, root -> right);
        return root;
    }
};
