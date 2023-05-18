class Solution {
public:
    int dp[201][201];
    int helper(int i, int j, vector<vector<int>>& tri){
        if(i == tri.size()) return tri[i - 1][j - 1];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(helper(i + 1, j, tri), helper(i + 1, j + 1, tri)) + tri[i - 1][j - 1];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof dp);
        return helper(1, 1, triangle);
    }
};