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
    ListNode *detectCycle(ListNode *head) {
        ListNode * pt1 = head;
        ListNode * pt2 = head;
        ListNode * meeting_point = NULL;
        while(pt1!=NULL && pt2!=NULL){
            pt1 = pt1->next;
            if (pt2->next==NULL)
                break;
            pt2 = pt2->next->next;
            if (pt1==pt2){
                meeting_point = pt1;
                break;
            }
        }
        if (meeting_point==NULL)
            return NULL;
        ListNode * loop_start = head;
        while(loop_start!=meeting_point){
            loop_start = loop_start->next;
            meeting_point = meeting_point->next;
        }
        return loop_start;
    }
};