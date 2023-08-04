class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> map(26);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); ++i){
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for(auto i: map)
            if(i != 0) return false;
        return true;
    }
};