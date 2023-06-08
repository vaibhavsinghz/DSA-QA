class Solution {
public:
    bool dfs(int i, vector <int> adj[], vector <int> &vis, vector <int> &inRec){
        vis[i] = inRec[i] = 1;
        bool flag = false;
        for(auto nbr: adj[i]){
            if(!vis[nbr]) flag = flag || dfs(nbr, adj, vis, inRec);
            else if(vis[nbr] && inRec[nbr]) return true;
        }
        inRec[i] = 0;
        return flag;
    }
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector <int> adj[v];
        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        vector <int> vis(v), inRec(v);
        for(int i = 0; i < v; ++i){
            if(!vis[i] && dfs(i, adj, vis, inRec)) return false;
        }
        return true;
    }
};