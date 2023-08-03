class Solution {
public:
    int dp[201][20001];
    bool helper(vector<int>& nums, int sum, int i){
        if(sum == 0) return true;
        if(i < 0 || sum < 0) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = helper(nums, sum - nums[i], i - 1);
        bool noTake = helper(nums, sum, i - 1);
        return dp[i][sum] = take || noTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto ele: nums){
            sum += ele;
        }
        if(sum & 1) return false;
        memset(dp, -1, sizeof dp);
        return helper(nums, sum / 2, n - 1);
    }
};