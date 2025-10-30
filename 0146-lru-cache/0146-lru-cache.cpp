class LRUCache {
private:
    int cap;
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>map;


public:


    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()) return -1;

        auto it = map[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        map[key]=cache.begin();

        return value;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            cache.erase(map[key]);
        }

        else if(cache.size()==cap){
            auto last= cache.back();
            map.erase(last.first);
            cache.pop_back();
        }

        cache.push_front({key,value});
        map[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */