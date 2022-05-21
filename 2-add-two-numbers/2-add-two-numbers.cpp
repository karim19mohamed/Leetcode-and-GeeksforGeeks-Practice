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
    int listlen (ListNode* l){
        int n=0;
        while (l!=NULL) ++n,l=l->next;
        return n;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode;
        ListNode* head=new ListNode;
        head=ans;
        int car=0;
        if (listlen(l2)>listlen(l1)) swap(l1,l2);
        while (l1!=NULL){
            if (l2!=NULL){
                ans->val = (l1->val+l2->val+car)%10;
                car = (l1->val+l2->val+car)/10;
                l2=l2->next;
            }else{
                ans->val = (l1->val+car)%10;
                car = (l1->val+car)/10;
            }
            l1=l1->next;
            if (l1!=NULL){
                ListNode* tmp=new ListNode;
                ans->next=tmp;
                swap(ans,tmp);
            }
        }
        if (car){
            ListNode* tmp=new ListNode;
            ans->next=tmp;
            tmp->val=car;
        }
        
        return head;
    }
};