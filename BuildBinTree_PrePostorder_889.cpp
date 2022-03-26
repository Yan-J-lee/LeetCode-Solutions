class Solution {
public:
    TreeNode *construct(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> postorder, int postStart, int postEnd) {
        // base case
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }
        if (preStart == preEnd || postStart == postEnd) {
            return new TreeNode(preorder[preStart]);
        }
        
        int rootVal = preorder[preStart];
        int leftRootVal = preorder[preStart+1];
        int index;
        for (int i = postStart; i < postEnd; ++i) {
            if (postorder[i] == leftRootVal) {
                index = i;
                break;
            }
        }
        
        int leftSize = index - postStart + 1;  // the number of nodes in left subtree
        TreeNode *root = new TreeNode(rootVal);
        root -> left = construct(preorder, preStart+1, preStart+leftSize, postorder, postStart, index);
        root -> right = construct(preorder, preStart+leftSize+1, preEnd, postorder, index+1, postEnd-1);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
