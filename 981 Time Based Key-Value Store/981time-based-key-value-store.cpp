class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyToValues;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyToValues[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!keyToValues.count(key))
            return "";
        auto &list = keyToValues[key];
        auto it = lower_bound(list.begin(), list.end(), make_pair(timestamp + 1, ""));
        if (it == list.begin())
            return "";
        it--;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */