class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 or i >= n or j < 0 or j >= m) return;
        if(vis[i][j] or (grid[i][j] -  '0' == 0)) return;
        vis[i][j] = 1;
        dfs(i + 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j - 1, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int count = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if((grid[i][j] -  '0' == 1) and !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};