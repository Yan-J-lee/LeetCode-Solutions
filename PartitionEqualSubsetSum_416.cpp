/* Knapsack Problem: given a knapsack with sum / 2 total weight and n items, each item has weight nums[i]. Is there a method to fill the knapsack to make it full? */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        else
            sum /= 2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        // base case
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;
        // state transition
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < sum+1; ++j) {
                // there is not enough space to store the ith item
                if (j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    // store the ith item or not
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};
