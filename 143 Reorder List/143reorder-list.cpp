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
    void reorderList(ListNode* head) {
        ListNode* p = head;
        int l = 0;
        while (p != NULL) {
            l++;
            p = p->next;
        }
        int pos = (l + 1)/2;
        int cnt = 1;
        ListNode* p1 = head;
        while (cnt < pos) {
            p1 = p1->next;
            cnt++;
        }
        p = p1;
        p1 = p1->next;
        p->next = NULL;

        ListNode* prev = NULL;
        while (p1 != NULL) {
            ListNode* next = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = next;
        }
        p1 = prev;
        ListNode dummy;
        ListNode* cur = &dummy;
        p = head;
        while (p != NULL && p1 != NULL) {
            ListNode* nP = p->next;
            ListNode* nP1 = p1->next;

            cur->next = p;
            p->next = p1;
            cur = p1;

            p = nP;
            p1 = nP1;
        }
        if (p != NULL) cur->next = p;
    }
};