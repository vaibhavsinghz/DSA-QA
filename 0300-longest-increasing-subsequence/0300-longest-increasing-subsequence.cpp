class Solution {
public:
    int dp[2501];
    int solve(int i, vector<int>& nums){
        if(i <= 0) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = 1; j < i; j++){
            if(nums[j-1] < nums[i-1]){
                ans = max(ans, solve(j, nums)+1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        int maxm = 1;
        for(int i = n; i > 0; i--){
            maxm = max(maxm, solve(i, nums));
        }
        return maxm;
    }
};