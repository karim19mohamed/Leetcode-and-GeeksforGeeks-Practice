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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* odd_starting = odd;
        ListNode* tmp = odd->next;
        bool alter = 1;        
        while(tmp){
            if(alter){
                even->next = tmp;
                tmp = tmp->next;
                even = even->next;
                even->next = nullptr;
            }else{
                odd->next = tmp;
                tmp = tmp->next;
                odd = odd->next;
                odd->next = nullptr;
            }
            alter ^= 1;
        }
        even->next = odd_starting;
        odd->next = nullptr;
        return head;
    }
};