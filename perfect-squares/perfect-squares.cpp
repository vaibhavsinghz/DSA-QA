class Solution {
public:
    int dp[10001];
    int helper(vector <int> &sq, int target){
        if(target <= 0) return 0;
        int ans = target;
        if(dp[target] != -1) return dp[target];
        for(int i = sq.size(); i > 0; --i){
            if(target >= sq[i - 1]){
                ans = min(ans, helper(sq, target - sq[i - 1]) + 1);
            }
        }
        return dp[target] = ans;
    }
    int numSquares(int n) {
        vector <int> sq;
        for(int i = 1; i <= sqrt(n); i++) sq.push_back(i * i);
        memset(dp, -1, sizeof dp);
        return helper(sq, n);
    }
};