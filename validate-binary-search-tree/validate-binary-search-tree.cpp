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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder; 
        TreeNode* cur = root;
        while(cur){
            if(!cur -> left){
                inorder.push_back(cur -> val);
                cur = cur -> right;
            }
            else{
                TreeNode* temp = cur -> left;
                while(temp -> right and temp -> right != cur) temp = temp -> right;
                if(!temp -> right){
                    temp -> right = cur;
                    cur = cur -> left;
                }
                else{
                    temp -> right = NULL;
                    inorder.push_back(cur -> val);
                    cur = cur -> right;
                }
            }
        }
        for(int i = 0; i < inorder.size() - 1; i++){
            cout<<inorder[i]<<" "<<i<<endl;
            if(inorder[i] >= inorder[i+1]) return false;
        }
        return true;
    }
};