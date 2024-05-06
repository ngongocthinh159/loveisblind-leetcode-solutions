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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* p = head;
        while (p != NULL) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode dummy;
        dummy.next = reverse(head);
        ListNode* p = dummy.next;
        while (p != NULL) {
            ListNode* next = p->next;
            while (next != NULL && next->val < p->val) {
                next = next->next;
            }
            p->next = next;
            p = next;
        }
        return reverse(dummy.next);
    }
};