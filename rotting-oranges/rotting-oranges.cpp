class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int vis[m][n];
        // {{r, c}, t}
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else{
                    vis[i][j] = 0;
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            for(int i = 0; i < 4; ++i){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1 and vis[nrow][ncol] != 2){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }            
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(vis[i][j] != 2 and grid[i][j] == 1) return -1;
            }
        }
        return tm;
    }
};