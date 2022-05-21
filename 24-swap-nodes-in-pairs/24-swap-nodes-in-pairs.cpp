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
    ListNode* rec(ListNode* pre){
        if (pre==nullptr) 
            return nullptr;
        if (pre->next==nullptr)
            return pre;
        ListNode* cur = pre->next;
        ListNode* new_pre = cur->next;
        // pre = cur->next;
        cur->next = pre;
        pre->next = rec(new_pre);
        return cur;
    }
    ListNode* iter(ListNode* head){
        if (head==nullptr || head->next==nullptr)
            return head;
        ListNode* pt1 = nullptr;
        ListNode* pt2 = head;
        ListNode* pt3 = head->next;
        ListNode* res = pt3;
        // cout << "adsad" << endl;
        while(pt3){
            // cout << pt2->val << " " << pt3->val << endl;
            if (pt1)
                pt1->next = pt3;
            pt2->next = pt3->next;
            pt3->next = pt2;
            pt1 = pt2;
            pt2 = pt2->next;
            if (pt2==nullptr)
                break;
            pt3 = pt2->next;
        }
        return res;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        // return iter(head);
        // if (head==nullptr)
        //     return head;
        return rec(head);
    }
};