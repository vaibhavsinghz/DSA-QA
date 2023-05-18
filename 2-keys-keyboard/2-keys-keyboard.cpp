class Solution {
public:
    int dp[1001][1001];
    int helper(int n, int ans, int clip){
        if(ans > n) return 1001;
        if(ans == n) return 0;
        if(dp[ans][clip] != -1) return dp[ans][clip];
        int copy = ans != clip ? helper(n, ans, ans) : 1001;
        int paste = clip != 0 ? helper(n, ans + clip, clip) : 1001; 
        return dp[ans][clip] = min(copy, paste) + 1;
    }
    int minSteps(int n) {
        memset(dp, -1, sizeof dp);
        return helper(n, 1, 0);
    }
};