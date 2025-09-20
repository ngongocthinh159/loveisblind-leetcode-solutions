struct Packet {
    int s, d, t;
    bool operator== (const Packet &p) const {
        return s == p.s && d == p.d && t == p.t;
    }
};
struct PHash {
    size_t operator() (const auto &p) const {
        size_t h1 = hash<int>()(p.s);
        size_t h2 = hash<int>()(p.d);
        size_t h3 = hash<int>()(p.t);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};
class Router {
public:
    unordered_map<int,deque<int>> desToTime; // <des, [time1, time2,..]>
    deque<pair<int,pair<int,int>>> q; // <src, <des, time>>
    unordered_set<Packet, PHash> S;
    int limit;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet key{source, destination, timestamp};
        if (S.count(key)) return false;

        // evict
        if (q.size() == limit) forwardPacket();

        // add
        S.insert(key);
        q.push_front({source, {destination, timestamp}});
        desToTime[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (!q.size()) return {};
        auto p = q.back();
        q.pop_back();
        int src = p.first;
        int des = p.second.first;
        int t = p.second.second;
        S.erase(Packet{src, des, t});
        desToTime[des].pop_front();
        return {src, des, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &list = desToTime[destination];
        return upper_bound(list.begin(), list.end(), endTime) - 
                lower_bound(list.begin(), list.end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */