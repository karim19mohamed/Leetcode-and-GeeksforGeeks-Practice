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
    ListNode* rev_head;
    bool rec(ListNode* head){
        if (head == nullptr){
            return 1;
        }
        bool res = rec(head->next);
        res &= (rev_head->val==head->val);
        rev_head = rev_head->next;
        return res;
    }
public:
    bool isPalindrome(ListNode* head) {
        rev_head = head;
        return rec(head);
    }
};