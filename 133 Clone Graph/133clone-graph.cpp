/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        deque<Node*> q;
        q.push_front(node);
        unordered_map<int,Node*> mp;
        set<Node*> visited;
        visited.insert(node);
        while (q.size()) {
            auto u = q.back(); q.pop_back();
            Node* copyU;
            if (!mp.count(u->val)) {
                copyU = new Node(u->val);
                mp[u->val] = copyU;
            } else copyU = mp[u->val];

            for (auto v : u->neighbors) {
                Node* copyV;
                if (!mp.count(v->val)) {
                    copyV = new Node(v->val);
                    mp[v->val] = copyV;
                } else copyV = mp[v->val];
                copyU->neighbors.push_back(copyV);    
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push_front(v);
                }
            }
        }
        return mp[node->val];
    }
};