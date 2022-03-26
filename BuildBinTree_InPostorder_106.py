class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # base case
        if not inorder or not postorder:
            return None
        
        root = TreeNode(postorder.pop())
        root_idx = inorder.index(root.val)
        root.right = self.buildTree(inorder[root_idx+1:], postorder)
        root.left = self.buildTree(inorder[:root_idx], postorder)
        return root
