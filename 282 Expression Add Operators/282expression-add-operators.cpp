#define ll long long
class Solution {
public:
    string cur = "";
    vector<string> res;
    vector<char> opers = {'+', '-', '*'};
    void dfs(int i, string &num, int target, char lastOperator, ll lastOperand, ll curOperand, ll curExpress) {
        ll newCurOperand = curOperand*10 + (num[i] - '0');
        cur += num[i];

        if (i == num.size() - 1) {
            if (lastOperator == '+') {
                curExpress += newCurOperand;
            } else if (lastOperator == '-') {
                curExpress -= newCurOperand;
            } else {
                curExpress = curExpress - lastOperand + newCurOperand*lastOperand;
            }
            if (curExpress == target) res.push_back(cur);
        } else {
            // chose only digit
            if (newCurOperand) dfs(i + 1, num, target, lastOperator, lastOperand, newCurOperand, curExpress);

            // chose digit + opers
            if (lastOperator == '+') {
                for (auto oper : opers) {
                    cur += oper;
                    dfs(i + 1, num, target, oper, newCurOperand, 0, curExpress + newCurOperand);
                    cur.pop_back();
                }
            } else if (lastOperator == '-') {
                for (auto oper : opers) {
                    cur += oper;
                    dfs(i + 1, num, target, oper, -newCurOperand, 0, curExpress - newCurOperand);
                    cur.pop_back();
                }
            } else if (lastOperator == '*') {
                for (auto oper : opers) {
                    cur += oper;
                    dfs(i + 1, num, target, oper, lastOperand*newCurOperand, 0, curExpress - lastOperand + lastOperand*newCurOperand);
                    cur.pop_back();
                }
            }
        }

        cur.pop_back(); // backtrack
    }
    vector<string> addOperators(string num, int target) {
        dfs(0, num, target, '+', 0, 0, 0);
        return res;
    }
};