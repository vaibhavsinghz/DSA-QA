class Solution {
public:
    int solve(int i, int crSum, int target, vector<int>& nums){
        if(i == 0 and crSum == target) return 1;
        if(i <= 0) return 0;
        int plus = solve(i - 1, crSum + nums[i - 1], target, nums);
        int minus = solve(i - 1, crSum - nums[i - 1], target, nums);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n, 0, target, nums);
    }
};