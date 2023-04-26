class Solution {
public:
    int dp[21][2002];
    int solve(int i, int crSum, int target, vector<int>& nums){
        if(i == 0 and crSum == target) return 1;
        if(i <= 0) return 0;
        if(dp[i][1001 + crSum] != -1) return dp[i][1001 + crSum];
        int plus = solve(i - 1, crSum + nums[i - 1], target, nums);
        int minus = solve(i - 1, crSum - nums[i - 1], target, nums);
        return dp[i][1001 + crSum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        int n = nums.size();
        return solve(n, 0, target, nums);
    }
};