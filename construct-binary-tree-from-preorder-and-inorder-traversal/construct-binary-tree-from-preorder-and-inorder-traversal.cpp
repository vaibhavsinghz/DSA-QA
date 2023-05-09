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
    int pStart = 0;
    TreeNode* helper(vector<int>& preorder, unordered_map <int, int> &inodr, int iStart, int iEnd){
        if(iStart > iEnd) return NULL;
        int curRoot = preorder[pStart];
        pStart++;
        TreeNode* root = new TreeNode(curRoot);
        if(iStart == iEnd) return root;
        int mid = inodr[curRoot];
        root -> left = helper(preorder, inodr, iStart, mid - 1);
        root -> right = helper(preorder, inodr, mid + 1, iEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int, int> inodr;
        for(int i = 0; i < inorder.size(); ++i){
            inodr[inorder[i]] = i;
        }
        return helper(preorder, inodr, 0, inorder.size() - 1);
    }
};