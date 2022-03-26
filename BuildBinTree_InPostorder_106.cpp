class Solution {
public:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder,
                    int inStart, int inEnd, int postStart, int postEnd) {
        // base case
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        
        // find and create the root node
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);
        
        // locate the root in the inorder traversal
        int root_idx;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == rootVal) {
                root_idx = i;
                break;
            }
        }
        
        // construct left and right subtrees recursively
        int leftSize = root_idx - inStart;
        root -> left = build(inorder, postorder, inStart, root_idx-1, postStart, postStart+leftSize-1);
        root -> right = build(inorder, postorder, root_idx+1, inEnd, postStart+leftSize, postEnd-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};

// class Solution(object):
//    def buildTree(self, inorder, postorder):
//        """
//        :type inorder: List[int]
//        :type postorder: List[int]
//        :rtype: TreeNode
//        """
//        # base case
//        if not inorder or not postorder:
//            return None
        
//        root = TreeNode(postorder.pop())
//        root_idx = inorder.index(root.val)
//        root.right = self.buildTree(inorder[root_idx+1:], postorder)
//        root.left = self.buildTree(inorder[:root_idx], postorder)
//        return root
