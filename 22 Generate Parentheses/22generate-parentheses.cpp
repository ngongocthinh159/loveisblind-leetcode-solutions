class Solution {
public:
    vector<char> path;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return ans;
    }

    void dfs(int lCnt, int rCnt, int n) {
        if (lCnt == n && rCnt == n) {
            string tmp;
            for (int i = 0; i < path.size(); i++) {
                tmp += path[i];
            }
            ans.push_back(tmp);
            return;
        }

        if (lCnt < n) {
            path.push_back('(');
            dfs(lCnt + 1, rCnt, n);
            path.pop_back();
        }
        
        if (rCnt < lCnt) {
            path.push_back(')');
            dfs(lCnt,rCnt+1,n);
            path.pop_back();
        }
    }
};