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
    stack <int> get_num_in_list(ListNode* tmp){
        stack<int> s;
        while (tmp != nullptr){
            s.push(tmp->val);
            tmp = tmp->next;
        }
        return s;
    }
    stack <int> summer(stack<int> s1, stack<int> s2){
        int rem = 0;
        stack<int> s3;
        while (!s1.empty() || !s2.empty()){
            if (!s1.empty() && !s2.empty()){
                int res = s1.top() + s2.top() + rem;
                rem = res/10;
                s3.push(res%10);
                s1.pop();
                s2.pop();
            }else if (!s1.empty()){
                int res = s1.top() + rem;
                rem = res/10;
                s3.push(res%10);
                s1.pop();
            }else{
                int res = s2.top() + rem;
                rem = res/10;
                s3.push(res%10);
                s2.pop();
            }
        }
        if (rem){
            s3.push(rem);
        }
        return s3;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,s3;
        s1 = get_num_in_list(l1);
        s2 = get_num_in_list(l2);
        s3 = summer(s1, s2);
        ListNode* ans = new ListNode;
        ListNode* tmp = ans;
        while (!s3.empty()){
            tmp->val = s3.top();
            s3.pop();
            if (!s3.empty()){
                tmp->next = new ListNode;
                tmp = tmp->next;
            }
        }
        return ans;
    }
};