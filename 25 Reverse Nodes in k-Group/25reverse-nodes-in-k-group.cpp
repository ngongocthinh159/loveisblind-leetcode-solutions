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
    ListNode* reverse(ListNode* head, int cnt, int k) {
        if (cnt < k) return head;
        ListNode* prev = nullptr;
        ListNode* p = head;
        while (cnt--) {
            ListNode* nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* dummy = new ListNode();
        ListNode* prevEnd = dummy;
        while (p != nullptr) {
            int cnt = 0;
            ListNode* startP = p;
            while (p != nullptr && cnt < k) {
                cnt++;
                p = p->next;
            }
            prevEnd->next = reverse(startP, cnt, k);
            prevEnd = startP;
        }
        return dummy->next;
    }
};