class Solution {
public:
    int minSwaps(string s) {
       int open = 0;
       // Reduce to unbalanced string first by increasing/decreasing the open brackets
       // The final number of open brackets will be the unblanced open brackets = unbalanced close brackets
       // The reduced string will have form: "]]]...[[[" => Each swap fix 2 open brackets (the swapped closed bracket will fix one extra open bracket)
       for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                if (open > 0) open--;
            } else open++;
       }
       return (open + 1)/2;
    }
};