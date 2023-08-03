class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n + 2];
        memset(dp, 0, sizeof dp);
        dp[0] = 0;
        dp[n + 1] = INT_MAX;
        dp[n] = cost[n - 1];
        dp[n - 1] = cost[n - 2];
        for(int i = n - 2; i > 0; i--){
            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i -  1];
        }
        return min(dp[1], dp[2]);
    }
};