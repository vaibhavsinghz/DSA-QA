class NumMatrix {
public:
    int dp[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(dp, 0, sizeof dp);
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i = 1; i <= c; i++) dp[1][i] = matrix[0][i-1] + dp[1][i-1]; // prefix for 1st row
        for(int i = 1; i <= r; i++) dp[i][1] = matrix[i -1][0] + dp[i - 1][1]; // prefix for 1st col
        
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
            }
        }
        
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++, r2++, c1++, c2++;
        
        return (dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]);
        /**
        dp[r1 - 1][c1 - 1] is getting subtracted 2 times 
        from dp[r2][c1 - 1] and dp[r1 - 1][c2]
        so we are adding it once to balance it
        */
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */