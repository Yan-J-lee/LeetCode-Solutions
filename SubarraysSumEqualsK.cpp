class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> preSum;
        preSum.resize(nums.size());
        preSum[0] = nums[0];
        // Prefix Sum
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] = preSum[i-1] + nums[i];  // preSum[i] = nums[0] + ... + nums[i]
        
        unordered_map<int, int> map;  // hash table (to avoid TLE)
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (preSum[i] == k)
                ++count;
            
            if (map.find(preSum[i]-k) != map.end())
                count += map[preSum[i]-k];
            
            ++map[preSum[i]];  // increment the value of the key preSum[i]
        }
        
        // Brute Force: calculate the sum of each subarray of nums (TLE)
        // int count = 0;
        // for (int i = 1; i <= nums.size(); ++i)
        //    for (int j = 0; j < i; ++j)
        //        if (preSum[i] - preSum[j] == k)  // nums[j] + ... + nums[i-1]
        //            ++count;
        
        return count;
    }
};
