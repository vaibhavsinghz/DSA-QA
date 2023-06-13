class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> row;
        unordered_map<string, int> col;
        for(int i = 0; i < n; ++i){
            string rn, cn;
            for(int j = 0; j < n; ++j){
                rn += to_string(grid[i][j]) + " ";
                cn += to_string(grid[j][i]) + " ";
            }
            row[rn]++;
            col[cn]++;
        }
        int count = 0;
        for(auto [a, b]: row){
            if(col.find(a) != col.end()){
                cout<<a<<endl;
                count += b * col[a];
            }
        }
        return count;
    }
};