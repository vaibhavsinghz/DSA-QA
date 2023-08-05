class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        ans[1] = nums[0];
        for(int i = 1; i < n - 1; ++i){
            ans[i + 1] = ans[i] * nums[i];
        }
        int mul = 1;
        for(int j = n - 1; j > 0; --j){
            mul *= nums[j];
            ans[j - 1] *= mul;
        }
        return ans;
    }
};