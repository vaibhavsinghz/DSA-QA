/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyList;
        copyList[NULL] = NULL;
        Node* cur = head;
        while(cur){
            copyList[cur] = new Node(cur -> val);
            cur = cur -> next;
        }
        cur = head;
        while(cur){
            Node* copy = copyList[cur];
            copy -> next = copyList[cur -> next];
            copy -> random = copyList[cur -> random];
            cur = cur -> next;
        }
        return copyList[head];
    }
};