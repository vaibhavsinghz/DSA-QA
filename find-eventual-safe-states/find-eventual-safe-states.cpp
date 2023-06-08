class Solution {
public:
    int dp[10000]; 
    bool dfs(int s, vector<vector<int>>& graph, vector <int> vis, vector <int> &inRec){
        if(dp[s] != -1) return dp[s];
        vis[s] = inRec[s] = 1;
        bool flag = false;
        for(auto place: graph[s]){
            if(!vis[place]) flag = flag ||  dfs(place, graph, vis, inRec);
            else if(vis[place] && inRec[place]) return dp[s] = true;
        }
        inRec[s] = 0;
        return dp[s] = flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        memset(dp, -1, sizeof dp);
        int v = graph.size();
        vector <int> vis(v), inRec(v), ans;
        for(int i = 0; i < v; ++i){
            if(!dfs(i, graph, vis, inRec)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};