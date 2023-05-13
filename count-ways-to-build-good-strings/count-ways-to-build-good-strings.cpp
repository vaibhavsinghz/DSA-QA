class Solution {
public:
    #define ll long long
    long long mod = 1e9 + 7;
    int dp[100001];
    int helper(int length, int low, int high, int zero, int one){
        if(length > high) return 0;
        if(dp[length] != -1) return dp[length];
        int res = length >= low ? 1 : 0;
        res += helper(length + zero, low, high, zero, one) + helper(length + one, low, high, zero, one);
        return dp[length] = res % mod;
    }    
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof dp);
        return helper(0, low, high, zero, one);
    }
};