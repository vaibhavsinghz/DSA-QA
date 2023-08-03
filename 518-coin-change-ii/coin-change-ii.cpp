class Solution {
public:
    int dp[301][5001];
    int helper(vector<int>& coins, int amt, int i){
        if(i < 0){
            if(amt == 0) return 1;
            else return 0;
        }
        if(dp[i][amt] != -1) return dp[i][amt];
        int take = 0, noTake = 0;
        noTake += helper(coins, amt, i - 1);
        if(amt >= coins[i]) take += helper(coins, amt - coins[i], i);
        return dp[i][amt] = take + noTake; 
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof dp);
        int n  = coins.size();
        return helper(coins, amount, n - 1);
    }
};