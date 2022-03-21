class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // base case
        if (root == NULL) {
            return NULL;
        }
        
        // swap lchild and rchild of root
        TreeNode *temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        
        invertTree(root -> left);
        invertTree(root -> right);
        
        return root;
    }
};
