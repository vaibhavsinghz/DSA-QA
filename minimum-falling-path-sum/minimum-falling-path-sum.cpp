class Solution {
public:
    int dp[101][101];
    int help(int i, int j, int r, int c, vector<vector<int>>& matrix){
        if(j < 1 or j > c) return INT_MAX;
        if(i == r) return dp[i][j] = matrix[i - 1][j - 1];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(help(i + 1, j + 1, r, c, matrix), min(help(i + 1, j, r, c, matrix), help(i + 1, j - 1, r, c, matrix))) + matrix[i - 1][j - 1];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= r; ++i){
            ans = min(ans, help(1, i, r, r, matrix));
        }
        return ans;
    }
};