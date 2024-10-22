struct DataStructure {
    unordered_map<int,int> numToFreq;
    set<pair<int,int>> low;
    set<pair<int,int>> hi;
    unordered_set<int> insertedHi;
    long long sum = 0;
    long long hiSum = 0;
    int topMostSize;

    DataStructure(int topMostSize) {
        this->topMostSize = topMostSize;
    }

    void insert(int val) {
        int freq = ++numToFreq[val];
        
        // update
        if (freq != 1) {
            // update in hi
            if (insertedHi.count(val)) { 
                hi.erase({freq - 1, val});
                hi.insert({freq, val});
                hiSum += val;
            } else { // update in low
                low.erase({freq - 1, val});
                low.insert({freq, val});
                relax();
            }
        } else {
            // insert
            low.insert({freq, val});
            relax();
        }

        sum += val;

        // for (auto p : hi ) {
        //     cout << p.first << " " << p.second << "\n";
        // }
        // cout << "\n";
    }

    void relax() { // move from low to hi
        if (insertedHi.size() < topMostSize) {
            while (low.size() && insertedHi.size() < topMostSize) {
                auto it = low.end();
                it--;
                auto p = *it;
                low.erase(it);

                hi.insert(p);
                insertedHi.insert(p.second);
                hiSum += p.second;
            }

            return;
        }

        if (low.size()) {
            auto it = hi.begin();
            auto pHi = *it;
            auto it2 = low.end();
            it2--;
            auto pLow = *it2;
            if (pHi.first < pLow.first || (pHi.first == pLow.first && pHi.second < pLow.second)) {
                hi.erase(it);
                low.erase(it2);

                hi.insert(pLow);
                low.insert(pHi);
                hiSum -= 1LL*pHi.second * pHi.first;
                hiSum += 1LL*pLow.second * pLow.first;
                insertedHi.erase(pHi.second);
                insertedHi.insert(pLow.second);
            }
        }
    }

    void remove(int val) {
        int freq = --numToFreq[val];
        
        if (insertedHi.count(val)) {
            hi.erase({freq + 1, val});
            if (freq != 0) hi.insert({freq, val});
            else insertedHi.erase(val);
            hiSum -= val;
            relax();
        } else {
            low.erase({freq + 1, val});
            if (freq != 0) low.insert({freq, val});
            relax();
        }

        sum -= val;

        // cout << "removed\n";
        // for (auto p : hi ) {
        //     cout << p.first << " " << p.second << "\n";
        // }
        // cout << "\n";
    }

    long long getTopMostSum() {
        if (insertedHi.size() < topMostSize) {
            return sum;
        }
        return hiSum;
    }
}; 
class Solution {
public:

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        DataStructure ds(x);
        for (int r = 0; r < k; r++) {
            ds.insert(nums[r]);
        }
        vector<long long> ans(nums.size() - k + 1);
        ans[0] = ds.getTopMostSum();
        for (int r = k; r < nums.size(); r++) {
            ds.insert(nums[r]);
            ds.remove(nums[r - k]);
            ans[r - k + 1] = ds.getTopMostSum();
        }
        return ans;
    }
};