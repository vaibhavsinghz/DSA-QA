class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        for(; i < letters.size(); ++i){
            if(target < letters[i]) return letters[i];
        }
        return letters[0];
    }
};