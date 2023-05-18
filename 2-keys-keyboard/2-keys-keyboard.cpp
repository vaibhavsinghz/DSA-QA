class Solution {
public:
    int helper(int n, int ans, int clip){
        if(ans > n) return 1001;
        if(ans == n) return 0;
        int copy = ans != clip ? helper(n, ans, ans) : 1001;
        int paste = clip != 0 ? helper(n, ans + clip, clip) : 1001; 
        return min(copy, paste) + 1;
    }
    int minSteps(int n) {
        return helper(n, 1, 0);
    }
};