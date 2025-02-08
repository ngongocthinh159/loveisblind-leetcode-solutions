class NumberContainers {
public:
    NumberContainers() {
        
    }
    unordered_map<int,int> idx_to_num;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> num_to_idxs;
    void change(int index, int number) {
        idx_to_num[index] = number;
        num_to_idxs[number].push(index);
    }
    
    int find(int number) {
        if (!num_to_idxs.count(number)) return -1;
        auto &m = num_to_idxs[number];
        while (m.size() && idx_to_num[m.top()] != number) m.pop();
        if (!m.size()) return -1;
        return m.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */