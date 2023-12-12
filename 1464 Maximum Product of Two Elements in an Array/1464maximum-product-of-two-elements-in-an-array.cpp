class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        for (auto num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = max(secondLargest, num);
            }
        }
        return 1LL*(largest-1)*(secondLargest-1);
    }
};