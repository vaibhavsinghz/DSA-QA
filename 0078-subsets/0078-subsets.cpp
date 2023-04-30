class Solution { // subset using bitmask
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsetCount = (1 << n);
        vector<vector<int>> subsets;
        for(int mask = 0; mask < subsetCount; mask++){
            vector <int> subset;
            for(int i = 0; i < n; i++){
                if((mask >> i) & 1){ //check if ith bit is set
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};