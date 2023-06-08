class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector <int> &vis){
        vis[i] = 1;
        for(auto key: rooms[i]){
            if(!vis[key]) dfs(key, rooms, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), m = rooms[0].size();
        vector <int> vis(n, 0);
        dfs(0, rooms, vis);
        return all_of(vis.begin(), vis.end(), [](int x) { return x == 1; });
    }
};