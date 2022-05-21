/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int get_size(ListNode *head){
        int sz = 0;
        while(head!=NULL){
            head = head->next;
            ++sz;
        }
        return sz;
    }
    ListNode * get_node(ListNode *headA, ListNode *headB, int szA, int szB){ // headA >= headB
        while(szA>szB){
            headA = headA->next;
            --szA;
        }
        while(headA!=headB && headA!=NULL && headB!=NULL){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int szA = get_size(headA);
        int szB = get_size(headB);
        if (szA>=szB){
            return get_node(headA, headB, szA, szB);
        }
        return get_node(headB, headA, szB, szA);
    }
};