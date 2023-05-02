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
    stack <TreeNode*> functionStack;
    stack <string> stateStack;
    void push(TreeNode* node, string state){
        functionStack.push(node);
        stateStack.push(state);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        push(root, "root");
        while(!functionStack.empty()){
            TreeNode* current = functionStack.top();
            functionStack.pop();
            string state = stateStack.top();
            stateStack.pop();
            
            if(current == NULL) continue;
            
            if(state == "root"){
                push(current, "left");
                ans.push_back(current -> val);
            }
            else if(state == "left"){
                push(current, "right");
                push(current -> left, "root");
            }
            else if(state == "right"){
                push(current, "end");
                push(current -> right, "root");
            }
        }
        return ans;
    }
};