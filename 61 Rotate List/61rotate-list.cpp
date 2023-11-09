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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        int cnt = 0;
        ListNode* p = head;
        ListNode* last;
        while (p != NULL) {
            cnt++;
            last = p;
            p = p->next;
        }
        if (cnt == 0 || cnt == 1) return dummy.next;
        int tmp = cnt - k % cnt;
        if (tmp == cnt) return dummy.next;
        p = head;
        ListNode* prev = &dummy;
        while (tmp != 0) {
            prev = p;
            p = p->next;
            tmp--;
        }
        prev->next = NULL;
        last->next = dummy.next;
        dummy.next = p;
        return dummy.next;
    }
};