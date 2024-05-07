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
    ListNode* doubleIt(ListNode* head) {
        int carry = dfs(head);
        if (carry) {
            ListNode* res = new ListNode(carry);
            res->next = head;
            return res;
        } else return head;
    }
    int dfs(ListNode* head) {
        if (head->next == NULL) {
            int val = head->val;
            head->val = val*2%10;
            return val*2/10;
        }
        int carry = dfs(head->next);
        int digit = (head->val)*2 + carry;
        head->val = digit%10;
        return digit/10;
    }  
};