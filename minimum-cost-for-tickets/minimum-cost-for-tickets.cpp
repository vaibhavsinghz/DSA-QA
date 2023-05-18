class Solution {
public:
    int dp[366];
    int helper(vector<int>& days, int d, int c1, int c2, int c3){
        if(d > days.back()) return 0;
        int i = lower_bound(days.begin(), days.end(), d) - days.begin();
        d = days[i];
        if(dp[d] != -1) return dp[d];
        return dp[d] = min(helper(days, d + 1, c1, c2, c3) + c1, min(helper(days, d + 7, c1, c2, c3) + c2, helper(days, d + 30, c1, c2, c3) + c3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof dp);
        return helper(days, days[0], costs[0], costs[1], costs[2]);
    }
};