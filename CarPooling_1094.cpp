/* 乘客上下车是否超载问题：乘客从上车的一战到下车的前一战，这个范围可以看作是对给定的区间内的元素进行增加操作；
   对给定区间内的元素进行增减操作：差分数组
*/

class Difference {
    private:
        vector<int> diff;
    
    public:
        Difference (vector<int> nums) {
            diff.resize(nums.size());
            diff[0] = nums[0];
            for (int i = 1; i < diff.size(); ++i)
                diff[i] = nums[i] - nums[i-1];
        }
    
        void increment (int i, int j, int val) {
            diff[i] += val;
            if (j + 1 < diff.size())
                diff[j+1] -= val;
        }
    
        vector<int> result() {
            vector<int> res;
            res.resize(diff.size());
            res[0] = diff[0];
            for (int i = 1; i < res.size(); ++i)
                res[i] = diff[i] + res[i-1];
            
            return res;
        }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums;
        nums.resize(1001);
        Difference diff = Difference(nums);
        for (vector<int> trip : trips) {
            int num = trip[0];  // the number of passengers in the trip
            int i = trip[1];  // the location i to pick them up
            int j = trip[2];  // the location j to drop them off
            diff.increment(i, j-1, num);
        }
        vector<int> numPassengers = diff.result();
        for (int i = 0; i < numPassengers.size(); ++i) {
            if (numPassengers[i] > capacity)
                return false;
        }
        return true;
    }
};
