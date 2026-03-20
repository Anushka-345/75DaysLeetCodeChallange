class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lruList; // stores {key, value}, front = MRU, back = LRU
    unordered_map<int, list<pair<int,int>>::iterator> cache; // key -> iterator in list

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move the accessed key-value pair to the front (MRU)
        auto it = cache[key];
        lruList.splice(lruList.begin(), lruList, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            auto it = cache[key];
            it->second = value;
            lruList.splice(lruList.begin(), lruList, it);
        } else {
            if (lruList.size() >= capacity) {
                // Remove LRU element
                auto lru = lruList.back();
                cache.erase(lru.first);
                lruList.pop_back();
            }
            // Insert new element at front
            lruList.push_front({key, value});
            cache[key] = lruList.begin();
        }
    }
};

/**
 * Usage:
 * LRUCache* obj = new LRUCache(capacity);
 * int val = obj->get(key);
 * obj->put(key, value);
 */