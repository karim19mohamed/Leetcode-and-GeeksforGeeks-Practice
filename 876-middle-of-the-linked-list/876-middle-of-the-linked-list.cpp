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
    ListNode* middleNode(ListNode* head) {
        ListNode* st = head, *en = head;
        bool flag = true;
        while(en){
            en = en->next;
            if (flag && en)
                st = st->next;
            flag ^= 1;
        }
        return st;
    }
};