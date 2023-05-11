class Solution {
public:
    int dp[2001][2001]; 
    int checkBackward(int i, int j, vector<int>& nums1, vector<int>& nums2){// 1 based indexing
        if(i == 0 or j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i - 1] == nums2[j - 1]) return dp[i][j] =  1 + checkBackward(i - 1, j - 1, nums1, nums2);
        else return dp[i][j] = max(checkBackward(i - 1, j, nums1, nums2), checkBackward(i, j - 1, nums1, nums2));

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        int n1 = nums1.size(), n2 = nums2.size();
        return checkBackward(n1, n2, nums1, nums2); 
    }
};