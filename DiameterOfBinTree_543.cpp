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
        int LD, RD;
        // base case
        if (tree == NULL) {
            return 0;
        }
        LD = getDepth(tree -> left);
        RD = getDepth(tree -> right);
        diameter = diameter > (LD+RD) ? diameter : (LD+RD);
        return (LD>RD?LD:RD) + 1;
    }
 
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return diameter;
    }
};
