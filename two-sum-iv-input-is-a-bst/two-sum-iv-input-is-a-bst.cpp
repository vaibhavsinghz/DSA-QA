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
    void order(TreeNode* root, vector <int> &inodr){
        if(!root) return;
        order(root -> left, inodr);
        inodr.push_back(root -> val);
        order(root -> right, inodr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector <int> inodr;
        order(root, inodr);
        unordered_set <int> nodes;
        for(auto i: inodr){
            if(nodes.find(k - i) != nodes.end()) return true;
            nodes.insert(i);
        }
        return false;
    }
};