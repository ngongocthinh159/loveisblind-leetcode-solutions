class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        if (n > 0) {
            double tmp = myPow(x,n/2);
            if (n%2==0) return tmp*tmp;
            else return tmp*tmp*x;
            
        } else {
            long long pow = (long long) n*(-1);
            double tmp = myPow(x,pow/2);
            if (pow%2==0) return 1/(tmp*tmp);
            else return 1/(tmp*tmp*x);
        }
    }
};