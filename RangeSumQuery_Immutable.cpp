// Prefix Sum (reduce T(n))

class NumArray {
    private: vector<int> preSum;  // preSum[i] == sum(nums[0]+...+nums[i-1])
    
    public:
        NumArray(vector<int> nums) {
            preSum.resize(nums.size()+1);
            for (int i = 1; i < preSum.size(); ++i)
                preSum[i] = preSum[i-1] + nums[i-1];
        }
    
        int sumRange(int left, int right) {
            return preSum[right+1] - preSum[left];
        }
};
