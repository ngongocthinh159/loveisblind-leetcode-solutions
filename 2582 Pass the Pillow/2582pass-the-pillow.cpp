class Solution {
public:
    int passThePillow(int n, int time) {
        int passed = time/(n - 1);
        int remain = time%(n - 1);
        bool start = true;
        if (passed&1) start = false;
        return (start ? 0 + remain : n - 1 - remain) + 1;
    }
};