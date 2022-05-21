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
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val<list2->val)
            swap(list1, list2);
        
        ListNode* sorted_list = new ListNode;
        ListNode* tmp = sorted_list;
        bool flag = false;
        while (list1!=nullptr && list2!=nullptr){
            if (flag){
                tmp->next = new ListNode;
                tmp = tmp->next;
            }
            if (list1->val < list2->val){
                tmp->val = list1->val;
                list1 = list1->next;
            }else if (list1->val > list2->val){
                tmp->val = list2->val;
                list2 = list2->next;
            }else{
                tmp->val = list1->val;
                list1 = list1->next;
                
                tmp->next = new ListNode;
                tmp = tmp->next;
                tmp->val = list2->val;
                list2 = list2->next;
            }
            flag = true;
        }
        if (list1!=nullptr){
            tmp->next = list1;
        }else if (list2!=nullptr){
            tmp->next = list2; 
        }
        return sorted_list;
    }
};