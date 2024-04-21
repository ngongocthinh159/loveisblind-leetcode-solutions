/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
    void dfs(Node* root) {
        if (root == NULL) return;
        
        Node* firstChild = NULL;
        Node* p = root;
        Node* prev = NULL;
        while (p != NULL) {
            if (p->left) {
                if (prev != NULL) {
                    prev->next = p->left;
                    prev = prev->next;
                } else {prev = p->left; firstChild = p->left;}
            }
            if (p->right) {
                if (prev != NULL) {
                    prev->next = p->right;
                    prev = prev->next;
                } else {prev = p->right; firstChild = p->right;}
            }
            p = p->next;
        }
        dfs(firstChild);
    }
};