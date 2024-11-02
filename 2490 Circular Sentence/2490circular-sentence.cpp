class Solution {
public:
    bool isCircularSentence(string sentence) {
        string prev = "";
        int i = 0;
        string first = "";
        while (i < sentence.size()) {
            string cur = "";
            while (i < sentence.size() && sentence[i] != ' ') {
                cur += sentence[i];
                i++;
            }
            if (prev != "") {
                if (cur[0] != prev.back()) return false;
            }
            if (first == "") {
                first = cur;
            }
            prev = cur;
            i++;
            if (i >= sentence.size()) {
                if (cur.back() != first[0]) return false;
            }
        }
        return true;
    }
};