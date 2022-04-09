/*
Solution 1 (TLE: 85/87)
Algorithm:
1. sorting the vectors based on the width in ascending order,
2. if the widths are the same, sorting the height in descending order,
3. extract the height vector and call the lengthOfLIS with the param height.
*/

class Solution {
    private:
        int lengthOfLIS(vector<int> nums) {
            vector<int> dp(nums.size(), 1);
            
            for (int i = 0; i < nums.size(); ++i)
                for(int j = 0; j < i; ++j)
                    if (nums[j] < nums[i])
                        dp[i] = max(dp[i], dp[j]+1);
            
            int res = INT_MIN;
            for (int val: dp)
                if (res < val)
                    res = val;
            
            return res;
        }
    
    public:
        // custom comparator
        static bool compare (const vector<int> &a const vector<int> &b) {
            // sorting based on the width in ascending order
            if (a[0] < b[0])
                return true;
            else if (a[0] > b[0])
                return false;
            else
                return a[1] > b[1];  // sorting based on the height in descending order
        }
    
        int maxEnvelopes(vector<vector<int>> & envelopes) {
            int n = envelopes.size();
            
            sort(envelopes.begin(), envelopes.end(), compare);  // PS: use the static keyword to avoid error
            
            vector<int> height(n);
            for (int i = 0; i < n; ++i)
                height[i] = envelopes[i][1];
            
            return lengthOfLIS(height);
        }
};

// Python (Accepted)
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key = lambda x: (x[0], -x[1]))
        height, res = [h for _, h in envelopes], []
        for h in height:
            idx = bisect.bisect_left(res, h)
            res[idx:idx+1] = [h]
        return len(res)
