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
private:
    ListNode* cur;
    bool rec(ListNode* node){
        if (node == NULL){
            return 1;
        }
        bool ret = rec(node->next);
        ret &= (cur->val == node->val);
        cur = cur->next;
        return ret;
    }
public:
    bool isPalindrome(ListNode* head) {
        cur = new ListNode();
        cur = head;
        bool ans = rec(head);
        return ans;
    }
};