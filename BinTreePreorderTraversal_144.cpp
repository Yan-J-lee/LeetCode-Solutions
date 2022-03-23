// Recursion
class Solution {
private:
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root) {
            res.push_back(root -> val);
            preorderTraversal(root -> left);
            preorderTraversal(root -> right);
        }
        return res;
    }
};

// Iterative approach using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *stack[100], *p;
        int top = -1;
        if (root) {
            stack[++top] = root;
            while (top != -1) {
                p = stack[top--];
                res.push_back(p -> val);
                if (p -> right != NULL)
                    stack[++top] = p -> right;
                if (p -> left != NULL)
                    stack[++top] = p -> left;
            }
        }
        return res;
    }
};
