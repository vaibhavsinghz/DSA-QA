class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i: nums) sum += i;
        int org = (n * (n + 1)) / 2;
        return org - sum;
    }
};