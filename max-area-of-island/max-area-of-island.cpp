class Solution {
public:
    int n, m;
    void dfs(int i, int j, int &count, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        if(!grid[i][j]) return;
        grid[i][j] = 0;
        count++;
        dfs(i + 1, j, count, grid);
        dfs(i, j + 1, count, grid);
        dfs(i - 1, j, count, grid);
        dfs(i, j - 1, count, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxm = 0, count;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j]){
                    count = 0;
                    dfs(i, j, count, grid);
                    maxm = max(maxm, count);
                }
            }
        }
        return maxm;
    }
};