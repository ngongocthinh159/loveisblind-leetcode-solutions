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
    int pairSum(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        int half_len = len/2;
        p = head;
        for (int i = 1; i < half_len; i++) {
            p = p->next;
        }
        ListNode* prev = NULL;
        ListNode* p1 = p->next;
        while (p1 != NULL) {
            ListNode* next = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = next;
        }

        p->next = prev;
        ListNode* l = head;
        ListNode* r = p->next;
        int ans = INT_MIN;
        for (int i = 1; i <= half_len; i++) {
            ans = max(ans, l->val + r->val);
            l = l->next;
            r = r->next;
        }
        return ans;
    }
};