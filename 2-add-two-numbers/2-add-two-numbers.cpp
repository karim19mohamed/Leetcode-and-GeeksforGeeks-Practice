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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        int rem = 0;
        bool flag = false;
        while (l1 != nullptr || l2 != nullptr){
            if (flag){
                tmp->next = new ListNode();
                tmp = tmp->next;
            }
            int val = rem;
            if (l1 != nullptr){
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                val += l2->val;
                l2 = l2->next;
            }
            rem = val/10;
            val %= 10;
            tmp->val = val;
            flag = true;
        }
        if (rem!=0){
            tmp->next = new ListNode();
            tmp = tmp->next;
            tmp->val = rem;
        }
        return res;
    }
};