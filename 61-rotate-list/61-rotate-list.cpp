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
    int get_sz(ListNode* head){
        int sz = 0;
        while(head){
            ++sz;
            head = head->next;
        }
        return sz;
    }
    void make_cycle(ListNode* head){
        ListNode* st = head;
        ListNode* en = head->next;
        while(en->next){
            en = en->next;
        }
        en->next = st;
        return;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int sz = get_sz(head);
        if (sz<2)
            return head;
        k = k%sz;
        if (k==0)
            return head;
        make_cycle(head);
        ListNode* pre = head;
        ListNode* cur = head->next;
        --sz;
        while(sz!=k){
            --sz;
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
        return cur;
    }
};