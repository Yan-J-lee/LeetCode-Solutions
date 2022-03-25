/* Algorithm:
1. find the maximum value in nums and create the root using the maximum
2. construct the left subtree based on the root recursively
3. build the right subtree based on the root recursively
*/

// C++ Recursion
class Solution {
    TreeNode *maximumBinaryTree(vector<int> nums, int low, int high) {
        // base case
        if (low > high) {
            return NULL;
        }
        
        int maxVal = nums[low];
        int k = low;
        for (int i = low + 1; i <= high; ++i) {
            if (nums[i] < maxVal) {
                nums[i] = maxVal;
                k = i;
            }
        }
        
        TreeNode *root = new TreeNode(maxVal);  // create the root using the maximum
        root -> left = maximumBinaryTree(nums, low, k-1);  // build the left subtree
        root -> right = maximumBinaryTree(nums, k+1, high);  // build the right subtree
        return root;
    }
    
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return maximumBinaryTree(nums, 0, nums.size()-1);
    }
};

// C++ Iterating using stack
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (!nums.empty()) {
            vector<TreeNode *> stack;
            TreeNode *last = nullptr;
            for (int num : nums) {
                while (!stack.empty() && stack.back() -> val < num) {
                    last = stack.back();
                    stack.pop_back();
                }
                TreeNode *node = new TreeNode(num);
                if (!stack.empty()) {
                    stack.back() -> right = node;
                }
                if (last != nullptr) {
                    node -> left = last;
                }
                stack.push_back(node);
                last = nullptr;
            }
            return stack.front();
        }
        else {
            return nullptr;
        }
    }
};

// Python Recursion
// class Solution(object):
//    def constructMaximumBinaryTree(self, nums):
//        """
//        :type nums: List[int]
//        :rtype: TreeNode
//        """
//        if nums:
//            max_idx, max_val = max(enumerate(nums), key=lambda x:x[1])
//            root = TreeNode(val=max_val)
//            root.left = self.constructMaximumBinaryTree(nums[:max_idx])
//            root.right = self.constructMaximumBinaryTree(nums[max_idx+1:])
//            return root
//        else:
//            return None
