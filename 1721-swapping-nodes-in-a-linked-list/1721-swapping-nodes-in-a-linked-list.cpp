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
    int list_size(ListNode* head){
        int sz=0;
        while(head!=NULL){
            head = head->next;
            ++sz;
        }
        return sz;
    }
    ListNode* get_kth_from_beginning(ListNode* head,int k){
        while(k--){
            head = head->next;
        }
        return head;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int list_sz = list_size(head);
        ListNode* node1 = new ListNode();
        ListNode* node2 = new ListNode();
        node1 = get_kth_from_beginning(head,k-1);
        node2 = get_kth_from_beginning(head,list_sz-k);
        // cout << node1->val << " " << node2->val << endl;
        swap(node1->val,node2->val);
        return head;
    }
};












