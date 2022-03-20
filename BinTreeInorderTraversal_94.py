# Recursive approach (Python)
def inorderTraversal(root):
  def inorder(bintree):  # Currying; LNR
    inorder_vals = []
    if bintree:
      inorder(root.left)
      inorder_vals.append(root.val)
      inorder(root.right)
    return inorder_vals
  return inorder(root)

# Iterating approach by using stack (C++)
# class Solution {
# public:
#    vector<int> inorderTraversal(TreeNode* root) {
#        TreeNode *p = root;  // p traverses the binary tree
#        TreeNode *stack[100];
#        int top = -1;
#        vector<int> result;
#        while (top != -1 || p != NULL) {
#            while (p != NULL) {
#                stack[++top] = p;
#                p = p -> left;
#            }
#            if (top != -1) {
#                p = stack[top--];
#                result.push_back(p -> val);
#                p = p -> right;
#            }
#        }
#        return result;
#    }
# };
