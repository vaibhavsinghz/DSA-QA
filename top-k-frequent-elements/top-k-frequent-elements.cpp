class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(auto num: nums) freq[num]++;
        vector<vector<int>> bucket(n + 1);
        for(auto [num, cnt]: freq){
            // cout<<num<<" "<<cnt<<endl;
            bucket[cnt].push_back(num);
        }
        // for(int i = 0; i <= n; ++i) cout <<i<<" "<<bucket[i]<<endl;
        vector <int> ans;
        int i = n;
        while(k){
            int j = bucket[i].size();
            if(j > 0){
                int ind = 0;
                while(k and ind < j){
                    ans.push_back(bucket[i][ind]);
                    ind++, k--;
                }
                // k--;
            }
            i--;
        }
        return ans;
    }
};