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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        while(tmp != nullptr){
            ListNode* new_next = tmp->next;
            ListNode* tmp_next = tmp->next;
            int cur = tmp->val;
            while(new_next != nullptr && cur == new_next->val){
                new_next = new_next->next;
            }
            tmp->next = new_next;
            tmp = tmp->next;
            while(tmp_next != nullptr && cur == tmp_next->val){
                ListNode* del_this = tmp_next;
                tmp_next = tmp_next->next;
                delete del_this;
                // cout << "true" << endl;
            }
            
        }
        return head;
    }
};



