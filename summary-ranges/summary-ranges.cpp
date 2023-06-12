class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector <string> ans;
        if(n == 0) return ans;
        int curr = nums[0];
        for(int i = 0; i < n; i++){
            if(i == n - 1 || nums[i] + 1 != nums[i + 1]){
                if(curr != nums[i]){
                    ans.push_back(to_string(curr) + "->" + to_string(nums[i]));
                }
                else
                    ans.push_back(to_string(curr));
                if(i != n - 1) curr = nums[i + 1];
            }
        }
        return ans;
    }
};