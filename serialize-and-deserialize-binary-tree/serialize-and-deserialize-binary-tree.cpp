/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans;
        queue <TreeNode*> lvl;
        lvl.push(root);
        while(!lvl.empty()){
            TreeNode* node = lvl.front();
            lvl.pop();
            if(!node) ans += "N ";//space to distinguish
            else{
                string temp = to_string(node -> val) + " ";//space to distinguish
                ans += temp;
                lvl.push(node -> left);
                lvl.push(node -> right);
            }
        }
        ans.pop_back();
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ' ');
        TreeNode* root = new TreeNode(stoi(str));
        queue <TreeNode*> lvl;
        lvl.push(root);
        while(!lvl.empty()){
            TreeNode* node = lvl.front();
            lvl.pop();

            getline(s, str, ' ');
            if(str == "N") node -> left = NULL;
            else{
                node -> left = new TreeNode(stoi(str));
                lvl.push(node -> left);
            }

            getline(s, str, ' ');
            if(str == "N") node -> right = NULL;
            else{
                node -> right = new TreeNode(stoi(str));
                lvl.push(node -> right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));