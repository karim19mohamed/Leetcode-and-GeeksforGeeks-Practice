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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead = nullptr;
        while(head && head->val==val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // cout << "adasd" << endl;
        newhead = head;
        if (newhead==nullptr)
            return newhead;
        ListNode* cur = newhead;
        head = head->next;
        while(head){
            // cout << head->val << endl;
            if (head->val!=val){
                cur->next = head;
                cur = cur->next;
                head = head->next;
            }else{
                ListNode* tmp = head;
                head = head->next;
                cur->next = nullptr;
                delete tmp;
            }
        }
        return newhead;
    }
};