/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* p = head;
        Node* res = new Node(head->val);
        Node* p1 = res;
        unordered_map<Node*, Node*> map;
        map[p] = p1;

        while (p != NULL) {
            Node* next = p->next;
            if (next == NULL) p1->next = NULL;
            else {
                p1->next = new Node(next->val);
                map[next] = p1->next;
            }
            p1 = p1->next;
            p = p->next;
        }
        p = head;
        p1 = res;
        while (p != NULL) {
            Node* random = p->random;
            if (random == NULL) p1->random = NULL;
            else {
                p1->random = map[random];
            }
            p1 = p1->next;
            p = p->next;
        }

        return res;
    }
};