class LFUCache {
public:
    map<int,list<int>> freqToList; // <freq / listOfKeysSameFreq>
    unordered_map<int, pair<int, pair<int, list<int>::iterator>>> keyToInfo; // <key / <val, <freq, iter>>>
    int capacity;
    LFUCache(int _capacity) : capacity(_capacity) {
        
    }
    
    int get(int key) {
        if (!keyToInfo.count(key)) {
            return -1;
        }

        auto &[val, p] = keyToInfo[key];
        auto &[oldFreq, oldIter] = p;
        int newFreq = oldFreq + 1;

        auto &oldList = freqToList[oldFreq];
        oldList.erase(oldIter);
        if (oldList.empty()) {
            freqToList.erase(oldFreq);
        }
        freqToList[newFreq].push_back(key);
        keyToInfo[key] = {val, {newFreq, --freqToList[newFreq].end()}};

        return val;
    }
    
    void put(int key, int value) {
        if (keyToInfo.count(key)) {
            get(key);
            int &curVal = keyToInfo[key].first;
            curVal = value;
            return;
        }
        
        // eviction
        if ((int) keyToInfo.size() == capacity) {
            int mnFreq = (*freqToList.begin()).first;
            auto &evictedList = freqToList[mnFreq];
            int evictedKey = evictedList.front();

            evictedList.pop_front();
            if (evictedList.empty()) {
                freqToList.erase(mnFreq);
            }
            keyToInfo.erase(evictedKey);
        }

        freqToList[1].push_back(key);
        keyToInfo[key] = {value, {1, --freqToList[1].end()}};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */