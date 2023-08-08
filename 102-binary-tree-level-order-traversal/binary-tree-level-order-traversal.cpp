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
        queue<TreeNode*> lvl;
        TreeNode* node = root;
        lvl.push(root);
        while(lvl.size()){
            int siz = lvl.size();
            vector<int> aLevel;
            for(int i = 0; i < siz; ++i){
                TreeNode *tmp = lvl.front();
                aLevel.push_back(tmp -> val);
                lvl.pop();
                if(tmp -> left) lvl.push(tmp -> left);
                if(tmp -> right) lvl.push(tmp -> right);
            }
            ans.push_back(aLevel);
        }
        return ans;
    }
};