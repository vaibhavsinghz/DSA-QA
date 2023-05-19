class Solution {
public:
    int sum, target;
    int dp[31][3001];
    int helper(int i, int total, vector<int>& stones){
        if(i == stones.size() or total >= target) return abs(total - (sum - total));
        if(dp[i][total] != -1) return dp[i][total];
        return dp[i][total] = min(helper(i + 1, total, stones), helper(i + 1, total + stones[i - 1], stones));
    }
    int lastStoneWeightII(vector<int>& stones) {
        sum = accumulate(stones.begin(), stones.end(), 0);
        target = sum / 2;
        memset(dp, -1, sizeof dp);
        return helper(1, 0, stones);

    }
};