class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int tmp = sqrt(sum);
        if (tmp*tmp==sum)return tmp;
        return -1;
    }
};