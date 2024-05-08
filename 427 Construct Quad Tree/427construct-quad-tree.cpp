/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> prf;
    int get_sum(int i1, int j1, int i2, int j2) {
        return prf[i2 + 1][j2 + 1] - prf[i1][j2 + 1] - prf[i2 + 1][j1] + prf[i1][j1];
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        prf = vector<vector<int>>(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            int row_sum = 0;
            int corner_sum;
            for (int j = 0; j < n; j++) {
                row_sum += grid[i][j];
                corner_sum = row_sum + prf[i][j + 1];
                prf[i + 1][j + 1] = corner_sum;
            }
        }
        Node* p = new Node();
        dfs(0, 0, n - 1, n - 1, p);
        return p;
    }
    void dfs(int i1, int j1, int i2, int j2, Node* p) {
        int len = i2 - i1 + 1;
        int halfLen = len/2;
        int sum = get_sum(i1, j1, i2, j2);
        if (sum == 0 || sum == len*len) {
            p->val = sum == 0 ? 0 : 1;
            p->isLeaf = true;
            return;
        } else {
            p->val = 1;
            p->isLeaf = false;

            p->topLeft = new Node();
            dfs(i1, j1, i2 - halfLen, j2 - halfLen, p->topLeft);
            
            p->topRight = new Node();
            dfs(i1, j1 + halfLen, i2 - halfLen, j2, p->topRight);
            
            p->bottomLeft = new Node();
            dfs(i1 + halfLen, j1, i2, j2 - halfLen, p->bottomLeft);

            p->bottomRight = new Node();
            dfs(i1 + halfLen, j1 + halfLen, i2, j2, p->bottomRight);
        }
    }
};