class Solution {
public:
    bool winnerOfGame(string colors) {
        int i = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        while (i < colors.size()) {
            bool isA = colors[i] == 'A' ? true : false;
            int cnt = 1;
            if (isA) {
                while (i + 1 < colors.size() &&  colors[i + 1] == 'A') {
                    cnt++; i++;
                }
                cnt1 += max(0,cnt-2);
            } else {
                while (i + 1 < colors.size() &&  colors[i + 1] == 'B') {
                    cnt++; i++;
                }
                cnt2 += max(0,cnt-2);
            }
            i++;
        }
        return cnt1 > cnt2;
    }
};