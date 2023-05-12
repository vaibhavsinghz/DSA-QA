#define ll long long
class Solution {
public:
    ll dp[100001];
    ll solve(int i, vector<vector<int>>& que, int n){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(que[i - 1][0] + solve(i + que[i - 1][1] + 1, que, n), solve(i + 1, que, n));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof dp);
        return solve(1, questions, questions.size());
    }
};