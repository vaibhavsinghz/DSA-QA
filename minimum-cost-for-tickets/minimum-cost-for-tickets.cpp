class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366];
        memset(dp, 0, sizeof(dp));
        int n = days.size();
        int j = 0; 
        for (int i = days[0]; i <= days[n - 1]; i++) {
            if (i == days[j]) {
                dp[i] = min(dp[max(0, i - 1)] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
                j++;
            } 
            else {
                dp[i] = dp[i - 1]; 
            }
        }

        return dp[days[n - 1]];
    }
};