class Solution {
public:
    void dfs(int s, vector <int> &vis, vector<vector<int>>& adj){
        vis[s + 1] = 1;
        for(int i = 0; i <  adj[s].size(); ++i){
            if(adj[s][i] and !vis[i + 1]) dfs(i, vis, adj);
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size(), count = 0;
        vector <int> vis(v + 1);
        for(int i = 0; i < v; ++i){
            if(!vis[i + 1]){
                dfs(i, vis, isConnected);
                count++;
            }
        }
        return count;
    }
};