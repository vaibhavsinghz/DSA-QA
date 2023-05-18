class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(r + 1, vector<int> (r + 2, 0));
        for(int i = 1; i <= r; ++i){
            dp[i][0] = dp[i][r + 1] = INT_MAX;
            dp[r][i] = matrix[r - 1][i - 1];
        }
        for(int i = r - 1; i > 0; --i){
            for(int j = r; j > 0; --j){
                dp[i][j] = min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1])) + matrix[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= r; ++i){
            ans = min(ans, dp[1][i]);
        }
        return ans;
    }
};