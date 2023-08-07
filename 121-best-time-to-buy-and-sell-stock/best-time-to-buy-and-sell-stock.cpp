class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), curMin = INT_MAX, maxm = 0;
        for(int i = 0; i < n; ++i){
            int temp = prices[i] - curMin;
            curMin = min(curMin, prices[i]);
            maxm = max(maxm, temp);
        }
        return maxm;
    }
};