class Solution {//amazon
public:
    int dp[21][21];
    bool solve(int i, int j, string &s1, string &s2){
        if(i == 0 and j == 0) return true;
        bool ans = false;
        if(i == 0){
            if(s2[j - 1] == '*'){
                return dp[i][j] = solve(i, j - 2, s1, s2);
            }
            else return false;
        }
        if(j == 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i - 1] == s2[j - 1]){// match
            ans = solve(i - 1, j - 1, s1, s2);
        }
        else{
            if(s2[j - 1] == '.'){
                ans = solve(i - 1, j - 1, s1, s2);
            }
            else if(s2[j - 1] == '*'){
                ans = solve(i, j - 2, s1, s2);
                // if(s2[j - 2] != s1[i - 1]) return false;
                if(s2[j - 2] == '.' || s2[j - 2] == s1[i - 1])
                    ans = ans or solve(i - 1, j, s1, s2);
            }
            
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return solve(s.size(), p.size(), s, p);
    }
};