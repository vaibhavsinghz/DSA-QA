class Solution {
public:
  int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);
        for(int i = n; i > 0; --i){
            for(int j = i; j > 0; --j){
                if(i == n) dp[i][j] = tri[i - 1][j - 1];
                else dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i - 1][j - 1];
            }
        }
        return dp[1][1];
    }
};