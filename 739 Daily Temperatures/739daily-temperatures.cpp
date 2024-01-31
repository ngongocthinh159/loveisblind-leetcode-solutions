class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ng(temperatures.size(),0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
int t = temperatures[i];
while (st.size() && temperatures[st.top()] < t) {
ng[st.top()] = i;
st.pop();
}
            st.push(i);
}
    for (int i =0; i < ng.size(); i++) {
        if (!ng[i]) continue;
        ng[i] = ng[i] - i;
    }
    return ng;
    }
};