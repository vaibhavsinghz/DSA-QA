//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* target;
    void markParent(Node* root, unordered_map <Node*, Node*> &parent, int burn){
        if(root -> data == burn) target = root;
        if(root -> left){ 
            parent.insert(make_pair(root -> left, root));
            markParent(root -> left, parent, burn);
        }
        if(root -> right){
            parent.insert(make_pair(root -> right, root));
            markParent(root -> right, parent, burn);

        }
    }
    int minTime(Node* root, int burn) 
    {
        if(!root) return 0;
        unordered_map <Node*, Node*> parent;
        markParent(root, parent, burn);
        // Node* target;
        // for(auto i: parent){
        //     if(i.first -> data == burn) target = i.first;
        // }
        vector <int> vis(10001, 0);
        int dis = 0;
        queue<Node*> radial;
        radial.push(target);
        vis[target -> data] = 1;
        while(!radial.empty()){
            int size = radial.size();
            for(int i = 0; i < size; i++){
                Node* temp = radial.front();
                radial.pop();
                if(temp -> left and !vis[temp -> left -> data]) {
                    radial.push(temp -> left);
                    vis[temp -> left -> data] = 1;
                }
                if(temp -> right and !vis[temp -> right -> data]) {
                    radial.push(temp -> right);
                    vis[temp -> right -> data] = 1;
                }
                if(temp != root and !vis[parent[temp] -> data]) {
                    radial.push(parent[temp]);
                    vis[parent[temp] -> data] = 1;
                }
            }
            dis++;
        }
        return dis - 1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends