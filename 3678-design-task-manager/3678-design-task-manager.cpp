class TaskManager {
public:
    unordered_map<int,int> taskToUser;   // taskId -> userId
    unordered_map<int,int> taskPriority; // taskId -> priority
    priority_queue<pair<int,int>> maxHeap; // (priority, taskId)

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskToUser[taskId] = userId;
            taskPriority[taskId] = priority;
            maxHeap.push({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskPriority[taskId] = priority;
        maxHeap.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        maxHeap.push({newPriority, taskId}); // push updated entry
    }

    void rmv(int taskId) {
        taskPriority.erase(taskId);
        taskToUser.erase(taskId);
        // lazy deletion: old entry in heap will be skipped later
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            if (taskPriority.find(taskId) != taskPriority.end() &&
                taskPriority[taskId] == priority) {
                // valid entry
                int userId = taskToUser[taskId];
                taskPriority.erase(taskId);
                taskToUser.erase(taskId);
                maxHeap.pop();
                return userId;
            }
            maxHeap.pop(); // stale entry
        }
        return -1; // no tasks
    }};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */