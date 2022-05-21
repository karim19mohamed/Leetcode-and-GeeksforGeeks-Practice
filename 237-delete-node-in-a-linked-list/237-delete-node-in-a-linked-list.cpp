/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node==NULL) return;
        
        node->val=node->next->val;
        if (node->next->next==NULL){
            ListNode* tmp=new ListNode;
            tmp=node->next;
            node->next=NULL;
            delete tmp;    
        }
        deleteNode(node->next);
    }
};