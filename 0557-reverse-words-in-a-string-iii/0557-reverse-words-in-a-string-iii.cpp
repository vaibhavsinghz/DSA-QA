class Solution {
public:
    string ans, temp;
    string reverseWords(string s) {
        int n = s.size();
        s += " ";
        for(int i = 0; i <= n; i++){
            if(s[i] == ' '){
                reverse(temp.begin(), temp.end());
                ans += temp;
                if(i < n) ans += " ";
                temp = "";
            }
            else temp.push_back(s[i]);
        }
        return ans;
    }
};