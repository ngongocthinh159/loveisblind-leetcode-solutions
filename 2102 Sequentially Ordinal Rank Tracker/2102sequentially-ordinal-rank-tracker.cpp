struct c1 {
    bool operator() (pair<string,int> &p1, pair<string,int> &p2) {
        if (p2.second > p1.second) return true;
        if (p2.second == p1.second && p2.first < p1.first) return true;
        return false;
    }
};
struct c2 {
    bool operator() (pair<string,int> &p1, pair<string,int> &p2) {
        if (p2.second < p1.second) return true;
        if (p2.second == p1.second && p2.first > p1.first) return true;
        return false;
    }
    bool operator() (const pair<string,int> &p1, const pair<string,int> &p2) {
        if (p2.second < p1.second) return true;
        if (p2.second == p1.second && p2.first > p1.first) return true;
        return false;
    }
};
class SORTracker {
priority_queue<pair<string,int>, vector<pair<string,int>>,c1> bot;
priority_queue<pair<string,int>, vector<pair<string,int>>,c2> top;
public:
    int query = 0;
    c2 cmp;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        bot.push({name, score});
        while (bot.size() && top.size() && cmp(bot.top(), top.top())) {
            auto p1 = bot.top(); bot.pop();
            auto p2 = top.top(); top.pop();
            bot.push(p2);
            top.push(p1);
        }
    }
    
    string get() {
        query++;
        while (top.size() < query) {
            top.push(bot.top());
            bot.pop();
        }
        return top.top().first;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */