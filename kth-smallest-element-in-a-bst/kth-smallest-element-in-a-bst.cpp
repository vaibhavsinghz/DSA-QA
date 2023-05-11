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
    void helper(vector <int> &nodes, TreeNode* root){
        if(!root) return;
        helper(nodes, root -> left);
        nodes.push_back(root -> val);
        helper(nodes, root -> right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> nodes;
        helper(nodes, root);
        return nodes[k - 1];
    }
};