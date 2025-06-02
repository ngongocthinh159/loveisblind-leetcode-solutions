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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        priority_queue<pair<int,ListNode*>> q;
        for (int i = 0; i < n; i++) {
            ListNode* p = lists[i];
            if (p != nullptr) {
                q.push({-p->val, p});
            }
        }
        while (q.size()) {
            auto [w, p] = q.top();
            q.pop();
            ListNode* nxt = p->next;
            res->next = p;
            res = res->next;
            res->next = nullptr;
            if (nxt != nullptr) {
                q.push({-nxt->val, nxt});
            }
        }
        return dummy->next;
    }
};