class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int m = tomatoSlices - 2 * cheeseSlices;
        if (m < 0 || m % 2 != 0) return {};
        int a = m / 2;
        int b = cheeseSlices - a;
        if (b < 0) return {};
        return {a, b};
    }
};