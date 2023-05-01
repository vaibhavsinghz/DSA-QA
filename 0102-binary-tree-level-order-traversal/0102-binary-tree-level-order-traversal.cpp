/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue <TreeNode*> bfs;
        bfs.push(root);
        while(bfs.size()){
            vector<int> level;
            int size = bfs.size();
            for(int i = 0; i < size; i++){
                TreeNode* lvlNode = bfs.front();
                bfs.pop();
                level.push_back(lvlNode -> val);
                if(lvlNode -> left) bfs.push(lvlNode -> left);
                if(lvlNode -> right) bfs.push(lvlNode -> right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};