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
    ListNode* tail;
    void rev (ListNode* pre, ListNode* head){
        if (head == nullptr){
            tail = pre;
            return;
        }
        rev (head, head->next);
        head->next = pre;
    }
    void iter_rev (ListNode* head){
        stack<ListNode*> s;
        ListNode* tmp = head;
        while (tmp != nullptr){
            s.push(tmp);
            tmp = tmp->next;
        }
        if (!s.empty())
            tail = s.top();
        while(!s.empty()){
            ListNode* a = s.top();
            s.pop();
            if (!s.empty()){
                a->next = s.top();
            }else{
                a->next = nullptr;
            }
        }
    }
public:
    ListNode* reverseList(ListNode* head) {
        iter_rev (head);
        // rev (nullptr, head);
        return tail;
    }
};