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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        stack <TreeNode*> dfs;
        dfs.push(root);
        while(dfs.size()){
            TreeNode* temp = dfs.top();
            dfs.pop();
            ans.push_back(temp -> val);
            /**Wil be adding right node first and left afterwords
            so that when we access the stack from top
            the left node comes first followed by second*/
            if(temp -> right) dfs.push(temp -> right);
            if(temp -> left) dfs.push(temp -> left);
        }
        return ans;
    }
};