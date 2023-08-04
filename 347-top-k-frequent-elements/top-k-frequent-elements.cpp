class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(auto i: nums) freq[i]++;
        vector <vector <int>> bucket(n + 1);
        for(auto [num, count]: freq){
            bucket[count].push_back(num);
        }
        vector <int> ans;
        for(int i = n; i >= 0; --i){
            for(auto el: bucket[i]){
                ans.push_back(el);
                if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};