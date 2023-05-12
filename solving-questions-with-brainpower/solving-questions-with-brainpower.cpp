#define ll long long
class Solution {
public:
    vector<ll> dp;

    ll solve(int i, vector<vector<int>>& que) {
        if (i >= que.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        ll points = que[i][0];
        int nextIndex = i + que[i][1] + 1;

        ll chooseCurrent = points + solve(nextIndex, que);
        ll skipCurrent = solve(i + 1, que);

        return dp[i] = max(chooseCurrent, skipCurrent);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n, -1);
        return solve(0, questions);
    }
};
