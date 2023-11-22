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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = & dummy;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* next = cur->next;
            if (next != NULL) {
                ListNode* nextNext = next->next;

                // Swap
                prev->next = next;
                next->next = cur;
                cur->next = nextNext;
            }
            prev = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};