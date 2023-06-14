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
    int prev = -1, curr, minm = INT_MAX;
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        if(prev != -1){
            minm = min(minm, abs(prev - root->val));
            prev = root -> val;
        }
        else if(prev == -1)
            prev = root -> val;
        // cout << root->val << " ";  
        inorderTraversal(root->right);    
    }
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minm;
    }
};