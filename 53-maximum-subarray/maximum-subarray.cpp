class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int subSum = 0, maxSum = INT_MIN;
        for(auto i: nums){
            subSum = max(i, subSum + i);
            maxSum = max(maxSum, subSum);
        }
        return maxSum;
    }
};