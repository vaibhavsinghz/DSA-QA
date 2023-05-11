/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void travel(TreeNode* root, vector<pair<TreeNode*, int>> &nodelvl, int lvl){
        nodelvl.push_back(make_pair(root, lvl));
        if(root -> left) {
            travel(root -> left, nodelvl, lvl+1);
            nodelvl.push_back(make_pair(root, lvl));
        }
        if(root -> right) {
            travel(root -> right, nodelvl, lvl+1);
            nodelvl.push_back(make_pair(root, lvl));
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<TreeNode*, int>> nodelvl;
        travel(root, nodelvl, 1);
        int ppos, qpos;
        for(int i = 0; i < nodelvl.size(); ++i){
            if(nodelvl[i].first == p) ppos = i;
            if(nodelvl[i].first == q) qpos = i;
        }
        if(ppos > qpos) swap(ppos, qpos);
        int minmlvl = nodelvl.size();
        TreeNode* node;
        for(int i = ppos; i <= qpos; ++i){
            if(nodelvl[i].second <= minmlvl){
                minmlvl = nodelvl[i].second;
                node = nodelvl[i].first;
            }
        }
        return node;
    }
};