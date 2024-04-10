class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int deckIdx = 0;
        int resIdx = 0;
        bool skip = false;
        vector<int> res(deck.size(), -1);
        while (deckIdx < deck.size()) {
            if (res[resIdx] == -1) {
                if (!skip) {
                    res[resIdx] = deck[deckIdx++]; 
                }
                skip = !skip;
            }
            resIdx = (resIdx + 1) % deck.size();
        }
        return res;
    }
};