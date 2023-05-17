class Solution {
public:
    int dp[10001];
    int helper(vector<int>& coins, int target){
        if(target == 0) return 0;
        if(dp[target] != -1) return dp[target];
        int ans = 1e9;
        for(int i = 0; i < coins.size(); i++){
            if(target >= coins[i]){
                ans = min(ans, helper(coins, target - coins[i]) + 1);
            }
        }
        return dp[target] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = helper(coins, amount);
        if(ans >= 1e9) return -1;
        return ans;
    }
};