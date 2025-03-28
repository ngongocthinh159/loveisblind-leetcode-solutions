#define ll long long
class MKAverage {
public:
    int idx = 0, m, k;
    deque<int> q;
    set<pair<int,int>> bot, mid, top;
    ll bot_sum = 0, mid_sum = 0, top_sum = 0;
    MKAverage(int m, int k) {
        this->m = m; 
        this->k = k;
    }
    
    void exchange(set<pair<int,int>> &bot, set<pair<int,int>> &top, ll &bot_sum, ll &top_sum) {
        if (bot.size() && top.size() && (*(--bot.end())).first > (*top.begin()).first) {
            auto it1 = --bot.end();
            auto it2 = top.begin();
            bot.insert(*it2);
            bot_sum += (*it2).first - (*it1).first;
            top.insert(*it1);
            top_sum += (*it1).first - (*it2).first;
            bot.erase(it1);
            top.erase(it2);
        }
    }
    void addElement(int num) {
        if (idx + 1 >= m + 1) {
            if (bot.erase({q.front(), idx - m}))
                bot_sum -= q.front();
            if (mid.erase({q.front(), idx - m}))
                mid_sum -= q.front();
            if (top.erase({q.front(), idx - m}))
                top_sum -= q.front();
            q.pop_front();
        }
        q.push_back(num);
        bot.insert({num, idx});
        bot_sum += num;
        exchange(bot, mid, bot_sum, mid_sum);
        exchange(mid, top, mid_sum, top_sum);
        if (idx + 1 >= m) {
            while (bot.size() > k) {
                auto it = --bot.end();
                mid.insert(*it);
                mid_sum += (*it).first;
                bot_sum -= (*it).first;
                bot.erase(it);
            }
            while (mid.size() > m - 2*k) {
                auto it = --mid.end();
                top.insert(*it);
                top_sum += (*it).first;
                mid_sum -= (*it).first;
                mid.erase(it);
            }
        }
        idx++;
    }
    
    int calculateMKAverage() {
        return idx < m ? -1 : mid_sum / (int) mid.size();
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */