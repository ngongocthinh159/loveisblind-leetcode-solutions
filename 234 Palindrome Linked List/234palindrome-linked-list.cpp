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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        int len2 = len - (len+1)/2;
        len = (len+1)/2;
        p = head;
        int cur = 1;
        while (cur < len) {
            cur++;
            p = p->next;
        }
        ListNode* p1 = p->next;
        ListNode* prev = NULL;
        while (p1!=NULL) {
            ListNode* next = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = next;
        }
        p1 = prev;
        p = head;
        int cnt = 0;
        while (cnt < len2) {
            cnt++;
            if (p->val != p1->val) return false;
            p = p->next;
            p1 = p1->next;
        }
        return true;
    }
};