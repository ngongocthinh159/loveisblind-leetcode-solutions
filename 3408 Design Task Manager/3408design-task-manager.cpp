class TaskManager {
public:
    struct cmp {
        bool operator() (const auto &p1, const auto &p2) const {
            return p1 > p2;
        }
    };
    set<pair<int,pair<int,int>>, cmp> taskQ; // <priority, taskId, uid>
    unordered_map<int,pair<int,int>> taskToInfo; // <taskId, <userId, priority>>
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskQ.insert({priority, {taskId, userId}});
        taskToInfo[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto &info = taskToInfo[taskId];
        int &oldP = info.second;
        int uid = info.first;
        taskQ.erase({oldP, {taskId, uid}});
        add(uid, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto &info = taskToInfo[taskId];
        int prior = info.second;
        int uid = info.first;
        taskQ.erase({prior, {taskId, uid}});
        taskToInfo.erase(taskId);
    }
    
    int execTop() {
        if (!taskQ.size()) return -1;
        auto p = *taskQ.begin();
        taskQ.erase(taskQ.begin());
        return p.second.second;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */