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
