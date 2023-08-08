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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        TreeNode* node = root;
        vector<int> ans;
        stack<TreeNode*> rec;
        // rec.push(node);
        while(true){
            if(node){
                rec.push(node);
                node = node -> left;
            }
            else{
                if(!rec.size()) break;
                node = rec.top();
                rec.pop();
                ans.push_back(node -> val);
                node = node -> right;

            }
        }
        return ans;
    }
};