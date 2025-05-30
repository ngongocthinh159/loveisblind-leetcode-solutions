#define ll long long
class MagicDictionary {
public:
    unordered_set<int> words;
    const ll base = 33;
    const int MOD = 1e9 + 7;
    vector<ll> basepow;
    MagicDictionary() {
        basepow.resize(105);
        basepow[0] = 1;
        for (int i = 1; i < 105; i++) 
            basepow[i] = basepow[i - 1] * base % MOD;
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto &w : dictionary) {
            ll cur = 0;
            for (int i = 0; i < w.size(); i++) {
                cur += (w[i] - 'a' + 1) * basepow[i] % MOD;
                if (cur >= MOD) cur -= MOD;
            }
            words.insert(cur);
        }
    }
    
    bool search(string searchWord) {
        ll cur = 0;
        for (int i = 0; i < searchWord.size(); i++) {
            cur += (searchWord[i] - 'a' + 1) * basepow[i] % MOD;
            if (cur >= MOD) cur -= MOD;
        }
        for (int i = 0; i < searchWord.size(); i++) {
            for (int c = 0; c < 26; c++) if (c != searchWord[i] - 'a') {
                ll hash = cur;
                hash -= (searchWord[i] - 'a' + 1) * basepow[i] % MOD;
                if (hash < 0) hash += MOD;
                hash += (c + 1) * basepow[i] % MOD; 
                if (hash >= MOD) hash -= MOD;
                if (words.count(hash)) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */