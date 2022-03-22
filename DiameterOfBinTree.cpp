// Diameter: the number of edges of the longest path in the binary tree
/*
Algorithm:
1. calculate the sum of depth of left and right subtree of a node
2. save and return the max sum, which is the diameter
*/

class Solution {
    private:
        int diameter = 0;
    public:
        int getDepth(TreeNode *tree) {
            // base case
            if (tree == NULL) {
                return 0;
            }
            else {
                int LD = getDepth(tree -> left);
                int RD = getDepth(tree -> right);
                return (LD>RD?LD:RD) + 1;
            }
        }
        
        void getDiameter(TreeNode *tree) {
            if (tree == NULL) {
                return 0;
            }
            else
            {
                int LeftDepth = getDepth(tree -> left);
                int RightDepth = getDepth(tree -> right);
                int temp = LeftDepth + RightDepth;
                diameter = temp > diameter ? temp : diameter;
                
                getDiameter(tree -> left);
                getDiameter(tree -> right);
            }
        }
        
        int diameterOfBinaryTree(TreeNode *root) {
            getDiameter(root);
            return diameter;
        }
};
