//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector <int> vis(v), ans;
        for(int i = 0; i < v; ++i){
            if(!vis[i]){
                queue<int> node;
                node.push(i);
                vis[i] = 1;
                while(!node.empty()){
                    int tmp = node.front();
                    node.pop();
                    ans.push_back(tmp);
                    
                    for(auto nbr: adj[tmp]){
                        if(!vis[nbr]){
                            vis[nbr] = 1;
                            node.push(nbr);
                        }
                    }
                }
            }
            break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends