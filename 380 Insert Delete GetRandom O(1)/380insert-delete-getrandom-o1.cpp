class RandomizedSet {
public:
    vector<int> numList;
    unordered_map<int,int> valToIdx;
    RandomizedSet() {
        
    }
    
    int getRandInRange(int l, int r) {
        int res = l + rand() % (r - l + 1);
        return res;
    }

    bool insert(int val) {
        if (valToIdx.count(val))
            return false;
        valToIdx[val] = numList.size();
        numList.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!valToIdx.count(val))
            return false;
        int idx = valToIdx[val];
        int lastIdx = numList.size() - 1;
        valToIdx[numList[lastIdx]] = idx;
        valToIdx.erase(val);
        swap(numList[idx], numList[lastIdx]);
        numList.pop_back();
        
        return true;
    }
    
    int getRandom() {
        return numList[getRandInRange(0, (int) numList.size() - 1)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */