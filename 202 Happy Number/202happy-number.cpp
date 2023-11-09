class Solution {
public:
    int goNext(int n) {
        int sum = 0;
        while (n != 0) {
            sum += pow((n%10),2);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        do {
            slow = goNext(slow);
            fast = goNext(fast);
            fast = goNext(fast);
            if (slow == 1 || fast == 1) return true;
        } while (slow != fast);
        return false;
    }
};