// Brute Force Recursion (TLE, 15/188)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0)
            return -1;
        // base case
        if (amount == 0)
            return 0;
        
        int res = INT_MAX;
        for (int coin : coins) {
            // obtain solutions of subproblems
            int subproblem = coinChange(coins, amount - coin);
            // ignore subproblems without solutions
            if (subproblem == -1)
                continue;
            res = (res > subproblem + 1) ? subproblem + 1 : res;
        }
        return res == INT_MAX ? -1 : res;
    }
};

// Top-to-Bottom Recursion with Memoization (TLE, 151/188)
class Solution {
private:
    vector<int> memo;  // size: amount + 1; each elem with the init val: -2
    
    int dp(vector<int> coins, int amount) {
        if (amount < 0)  // no solution
            return -1;
        // base case
        if (amount == 0)
            return 0;
        
        // avoid the repetitious call to memo[amount]
        if (memo[amount] != -2)
           return memo[amount];
        
        int res = INT_MAX;
        for (int coin : coins) {
            // compute the solutions of subproblems
            int subproblem = dp(coins, amount - coin);
            if (subproblem != -1)
                res = min(res, subproblem + 1);  // update the min res
        }
        
        memo[amount] = (res == INT_MAX) ? -1 : res;
        return memo[amount];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1);
        fill(memo.begin(), memo.end(), -2);
        return dp(coins, amount);
    }
};

// Dynamic Programming
int coinChange(vector<int> &coins, int amount) {
  vector<int> dp(amount + 1);
  fill(dp.begin(), dp.end(), amount + 1);  // equivalent to vector<int> dp(amount+1, amount+1)
  
  dp[0] = 0;
  for (int i = 1; i < dp.size(); ++i) {
      for (int coin : coins) {
          if (i >= coin) {
              dp[i] = min(dp[i], dp[i-coin] + 1);  // state transition
          }
      }
  }
  
  return (dp[amount] > amount) ? -1 : dp[amount];
}
