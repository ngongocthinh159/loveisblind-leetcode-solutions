class FoodRatings {
public:
    struct cmp {
        bool operator() (const auto &p1, const auto &p2) const {
            if (p1.first > p2.first) return true;
            if (p1.first == p2.first && p1.second < p2.second) return true;
            return false;
        }
    };
    unordered_map<string,set<pair<int,string>,cmp>> cToF; // <cuisine, <rating, food>>
    unordered_map<string,pair<string,int>> fToInfo; // <food, <cuisine, rating>>
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            cToF[cuisines[i]].insert({ratings[i], foods[i]});
            fToInfo[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &info = fToInfo[food];
        string c = info.first;
        int &rating = info.second;
        cToF[c].erase({rating, food});
        cToF[c].insert({newRating, food});
        rating = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cToF[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */