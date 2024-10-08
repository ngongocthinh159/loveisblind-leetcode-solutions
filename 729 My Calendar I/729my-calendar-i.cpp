struct Node {
    pair<int,int> val;
    Node* left;
    Node* right;
    Node(int start, int end) {
        val = {start, end};
        left = NULL;
        right = NULL;
    }
};
struct Tree {
    Node* root;
    Tree() {
        root = NULL;
    }
    bool insert(int start, int end) {
        if (root == NULL) {
            root = new Node(start, end);
            return true;
        }
        auto cur = root;
        while (true) {
            if (start >= cur->val.second) {
                if (cur->right == NULL) {
                    cur->right = new Node(start, end);
                    return true;
                }
                cur = cur->right;
            } else if (end <= cur->val.first) {
                if (cur->left == NULL) {
                    cur->left = new Node(start, end);
                    return true;
                }
                cur = cur->left;
            } else {
                return false;
            }
        }
    }
};

class MyCalendar {
public:
    Tree tree;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        return tree.insert(start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */