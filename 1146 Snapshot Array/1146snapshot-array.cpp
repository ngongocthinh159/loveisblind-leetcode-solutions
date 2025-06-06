class SnapshotArray {
public:
    vector<vector<pair<int,int>>> idxToSnap;
    int id = 0;
    SnapshotArray(int length) {
        idxToSnap.resize(length);
        for (int i = 0; i < length; i++) {
            idxToSnap[i].push_back({-1, 0});
        }
    }
    
    void set(int index, int val) {
        idxToSnap[index].push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(idxToSnap[index].begin(), idxToSnap[index].end(), make_pair(snap_id, INT_MAX));
        it--;
        return (*it).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */