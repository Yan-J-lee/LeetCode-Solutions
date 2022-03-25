// Tips: draw the preorder and inorder diagram to help solve the problem

class Solution {
public:
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd) {
        // base case
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int index;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }
        int leftSize = index - inStart;  // the size of left subtree
        root -> left = build(preorder, preStart+1, preStart+leftSize,
                             inorder, inStart, index-1);
        root -> right = build(preorder, preStart+leftSize+1, preEnd,
                              inorder, index+1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1);
    }
};
