class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int freq[32]{};
        for (int i = 0; i < nums.size(); i++) {
            int msb = 32 - __builtin_clz(nums[i]) - 1;
            freq[msb]++;
        }
        int oper = 0;
        for (int bit = 0; bit <= 30; bit++) {
            if ((target >> bit) & 1) {
                if (freq[bit]) {
                    freq[bit]--;
                } else {
                    bool f = false;
                    for (int j = bit + 1; j <= 30; j++) if (freq[j]) {
                        f = true;

                        int k = j;
                        while (k != bit) {
                            freq[k]--;
                            freq[k - 1]++;
                            freq[k - 1]++;
                            oper++;
                            k--;
                        }
                        freq[bit]--;

                        break;
                    }
                    if (!f)
                        return -1;
                    
                }
            }

            freq[bit + 1] += freq[bit] / 2;
            freq[bit] = freq[bit] & 1;
        }
        return oper;
    }
};