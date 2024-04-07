class Solution {
public:
    bool checkValidString(string s) {
        vector<int> open; // hold open bracket idx
        vector<int> star; // hold star idx
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') open.push_back(i);
            else if (c == '*') star.push_back(i);
            else { // close bracket case need 1 open or star
                if (open.size()) open.pop_back(); // greedy use open bracket first if have (star can be empty so use open first)
                else if (star.size()) { // if open bracket is empty => use star as open bracket
                    star.pop_back();
                } else return false;
            }
        }
        // If can reach here meaning all the close bracket can be satisfied
        // Start to check for remaining open bracket, which are already in the open array
        // The remaining open bracket only can be closed by star because all the close bracket have been delete from above for loop
        int i = 0, j = 0;
        while (i < open.size() && j < star.size()) {
            if (star[j] < open[i]) j++;
            else if (open[i] < star[j]) {i++; j++;} // use star to satisfy an open bracket when idx star > idx bracket
        }
        return i == open.size(); // only valid if we can satisfy all open bracket
    }
};