class LRUCache {
public:
    list<int> usedKeys;
    unordered_map<int,pair<list<int>::iterator, int>> keyToInfo;
    int sz;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if (!keyToInfo.count(key))
            return -1;
        
        auto &[iter, val] = keyToInfo[key];
        usedKeys.erase(iter);
        usedKeys.push_back(key);
        keyToInfo[key] = {--usedKeys.end(), val};

        return val;
    }
    
    void put(int key, int value) {
        if (keyToInfo.count(key)) {
            get(key);
            keyToInfo[key] = {--usedKeys.end(), value};
            return;
        }
        
        // evict key
        if ((int) keyToInfo.size() == sz) {
            int removedKey = usedKeys.front();
            usedKeys.pop_front();
            keyToInfo.erase(removedKey);
        }
        
        usedKeys.push_back(key);
        keyToInfo[key] = {--usedKeys.end(), value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */