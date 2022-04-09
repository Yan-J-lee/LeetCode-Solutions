// Dynamic Programming (very similar to Length of LIS)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        
        // base case
        dp[0] = nums[0];
        
        // state transition
        for (int i = 1; i < dp.size(); ++i) {
            // dp[i]: the sum of the maximum contiguous subarray ended with nums[i]
            if (dp[i-1] > 0)
                dp[i] = max(dp[i], dp[i-1] + nums[i]);
            else
                dp[i] = nums[i];
        }
        
        int res = INT_MIN;
        for (int val : dp)
            if (res < val)
                res = val;
        
        return res;
    }
};
