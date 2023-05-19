class Solution {
public:
   int numSquares(int n) {
        vector <int> sqs, dp(n + 1, 10001);
        dp[0] = 0;
        for(int i = 1; i <= sqrt(n); i++) sqs.push_back(i * i);
        for(int target = 1; target <= n; ++target){
            for(auto sq: sqs){
                if(target >= sq) dp[target] = min(dp[target], dp[target - sq] + 1);
            }
        }
        return dp[n]; 
    }
};