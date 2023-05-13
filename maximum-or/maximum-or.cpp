class Solution {
public:
    #define ll long long
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; ++i){
            pre[i] = nums[i] | pre[i - 1];
        }
        suf[n - 1] = nums[n - 1];
        for(int j = n - 2; j >= 0; --j){
            suf[j] = nums[j] | suf[j + 1];
        }
        ll pwr = pow(2, k), maxm = INT_MIN;
        for(int i = 0; i < n; ++i){
            ll curNum = nums[i];
            ll changedNum = curNum * pwr;
            int prevOr = 0, nextOr = 0;
            if(i > 0) prevOr = pre[i - 1];
            if(i < n - 1) nextOr = suf[i + 1];
            maxm = max(maxm, prevOr | changedNum | nextOr);
        }
        return maxm;
    }
};