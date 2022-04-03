/* 此应用题可用差分数组的算法解决（要具备抽象思维能力） */

class Difference {
    private: vector<int> diff;
    
    public:
        Difference (vector<int> nums) {
            diff.resize(nums.size());
            diff[0] = nums[0];
            for (int i = 1; i < diff.size(); ++i)
                diff[i] = nums[i] - nums[i-1];
        }
    
        void increment(int i, int j, int val) {
            diff[i] += val;
            if (j+1 < diff.size())
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer;
        answer.resize(n);
        Difference diff = Difference(answer);
        for (vector<int> booking : bookings) {
            int i = booking[0];  // flight i
            int j = booking[1];  // flight j
            int num = booking[2];  // the number of reserved seats
            diff.increment(i-1, j-1, num);
        }
        return diff.result();
    }
};
