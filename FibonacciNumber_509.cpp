// Recursion
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        else
            return fib(n-1) + fib(n-2);
    }
};

// Dynamic Programming
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        vector<int> dp;
        dp.resize(n+1);
        // base case
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];  // state transition
        return dp[n];
    }
};

// improved DP (avoid DP Table; reduce S(n) from O(n) to O(1))
class Solution {
public:
    int fib(int n) {
        // base case
        if (n == 0 || n == 1)
            return n;
        
        int dp_i_1 = 1;  // dp[i-1]
        int dp_i_2 = 0;  // dp[i-2]
        
        for (int i = 2; i <= n; ++i) {
            // state transition
            int dp_i = dp_i_1 + dp_i_2;  // dp[i] = dp[i-1] + dp[i-2]
            dp_i_2 = dp_i_1;  // dp[i-2] = dp[i-1]
            dp_i_1 = dp_i;  // dp[i-1] = dp[i]
        }
        
        return dp_i_1;
    }
};
