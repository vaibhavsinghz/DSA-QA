class Solution {
public:
    int dp[10001];
     int helper(vector<int>& coins, int amount){
         if(amount == 0) return 0;
         if(dp[amount] != -1) return dp[amount];
         int ans = 1e9;
         for(auto coin: coins){
            if(amount >= coin) ans = min(ans, helper(coins, amount - coin) + 1);
         }
         return dp[amount] = ans;
     }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = helper(coins, amount);
        if(ans >= 1e9) ans = -1;
        return ans;
    }
};