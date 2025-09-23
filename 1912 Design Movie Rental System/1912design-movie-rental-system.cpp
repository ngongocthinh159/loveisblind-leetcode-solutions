class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> unrent; // <movieId, <price, shopId>>
    set<pair<int,pair<int,int>>> rented; // <price, <shopId, movieId>>
    unordered_map<int,unordered_map<int,int>> movieInfo; // [moveId][shopId] -> price
    int MX = 5;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shopId = e[0];
            int movieId = e[1];
            int price = e[2];
            unrent[movieId].insert({price, shopId});
            movieInfo[movieId][shopId] = price;
        }
    }
    
    vector<int> search(int movie) {
        auto &list = unrent[movie];
        auto it = list.begin();
        vector<int> res;
        for (int cnt = 0; cnt < MX && it != list.end(); it++, cnt++) {
            res.push_back(it->second);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        // if (!movieInfo[movie].count(shop)) return;
        int price = movieInfo[movie][shop];
        unrent[movie].erase({price, shop});
        rented.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        // if (!movieInfo[movie].count(shop)) return;
        int price = movieInfo[movie][shop];
        unrent[movie].insert({price, shop});
        rented.erase({price, {shop, movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        auto it = rented.begin();
        for (int cnt = 0; cnt < MX && it != rented.end(); cnt++, it++) {
            res.push_back({(it->second).first, (it->second).second});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */