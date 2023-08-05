class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // int r = board.size(), c = board[0].size();
        int row[9][10] = {0}, col[9][10] = {0}, sq[3][3][10] = {0};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                char digit = board[i][j] - '0';
                if(row[i][digit] || col[j][digit] || sq[i/3][j/3][digit]) return false;
                else{
                    row[i][digit] = col[j][digit] = sq[i/3][j/3][digit] = 1;
                }
            }
        }
        return true;
    }
};