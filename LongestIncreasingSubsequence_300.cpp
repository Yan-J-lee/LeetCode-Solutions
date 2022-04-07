class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        // state transition
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);  // dp[i]: the length of the longest increasing subsequence ended with nums[i]
            }
        }
        
        int res = INT_MIN;
        for (int i = 0; i < dp.size(); ++i)
            if (res < dp[i])
                res = dp[i];
        
        return res;
    }
};
