/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool rec(ListNode *head){
        if (head == NULL){
            return false;
        }
        if (head->val == -10000000)
            return true;
        
        bool res = false;
        int tmp = head->val;
        head->val = -10000000;
        res |= rec(head->next);
        head->val = tmp;
        return res;
    }
public:
    bool hasCycle(ListNode *head) {
        return rec(head);
    }
};