class MedianFinder {
public:
    multiset<int> bot, top;
    int sz;
    MedianFinder() {
        sz = 0;
    }
    
    void addNum(int num) {
        sz++;
        bot.insert(num);
        while (bot.size() && top.size() && *(--bot.end()) > *(top.begin())) {
            auto itb = --bot.end();
            auto valb = *itb;
            auto itt = top.begin();
            auto valt = *itt;
            bot.erase(itb);
            top.erase(itt);
            bot.insert(valt);
            top.insert(valb);
        }

        int topSz = (sz + 1)/2;
        while (bot.size() && top.size() < topSz) {
            auto itb = --bot.end();
            top.insert(*itb);
            bot.erase(itb);
        }
    }
    
    double findMedian() {
        if (sz&1)
            return *top.begin();
        else
            return 1.00 * (*(--bot.end()) + *(top.begin())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */