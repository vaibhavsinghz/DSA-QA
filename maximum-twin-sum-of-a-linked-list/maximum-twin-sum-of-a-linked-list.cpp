/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> pair;
        int n = 0;
        while(head){
            pair.push_back(head -> val);
            head = head -> next;
            n++;
        }
        int maxm = 0;
        for(int i = 0; i < n / 2; ++i){
            pair[i] += pair[n - 1 - i];
            maxm = max(maxm, pair[i]);
        }
        return maxm;
    }
};