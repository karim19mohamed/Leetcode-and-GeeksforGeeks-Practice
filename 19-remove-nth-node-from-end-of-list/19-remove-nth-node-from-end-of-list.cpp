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
    int idx;
    int target;
    bool last;
    ListNode* rec(ListNode* head){
        if (head==nullptr){
            last = true;
            return head;
        }
        ListNode* new_nxt = rec(head->next);
        if (last){
            ++idx;
        }
        if (target==idx){
            ListNode* tmp = head->next;
            delete head;
            return tmp;
        }
        head->next = new_nxt;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        idx = 0;
        target = n;
        last = false;
        ListNode* ans = rec(head);
        return ans;
    }
};