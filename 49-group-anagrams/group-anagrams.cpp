class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector <string>> anag;
        for(auto str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            anag[tmp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto [st, grp]: anag){
            ans.push_back(grp);
        }
        return ans;
    }
};