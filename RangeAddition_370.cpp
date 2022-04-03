/* Difference Array */

class Difference {
    private: vector<int> diff;
    
    public:
        // constructor: build difference array
        Difference (vector<int> nums) {
            assert nums.size() > 0;
            diff.resize(nums.size());
            diff[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                diff[i] = nums[i] - nums[i-1];
            }
        }
    
        // increase val (may negative) to array elem in range [i, j]
        void increment (int i, int j, int val) {
            diff[i+1] += val;
            if (j+1 < diff.size())
                diff[j+1] -= val;
        }
    
        // return the result array
        vector<int> result() {
            vector<int> res;
            res.resize(diff.size());
            res[0] = diff[0];
            for (int i = 1; i < res.size(); ++i) {
                res[i] = diff[i] + res[i-1];
            }
            return res;
        }
};

vector<int> getModifiedArray(int length, vector<vector<int>> updates) {
    vector<int> nums;
    nums.resize(length);
    Difference diff = new Difference(nums);
    for (vector<int> update: updates) {
        int i = update[0];  // start index
        int j = update[1];  // end index
        int inc = update[2];  // increase value
        diff.increment(i, j, inc);
    }
    return diff.result();
}
