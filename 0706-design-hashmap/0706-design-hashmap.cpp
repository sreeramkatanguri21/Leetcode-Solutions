class MyHashMap {
public:
    vector<list<pair<int,int>>> buckets;
    int M;
    MyHashMap() {
        M = 15000;
        buckets.resize(M, list<pair<int,int>>{});
    }

    int getIdx(int key) {
        return key%M;
    }
    list<pair<int,int>>::iterator findKey(int key, int idx) {
        list<pair<int,int>>::iterator it = buckets[idx].begin();

        while(it != buckets[idx].end()) {
            auto [k, v] = *it;
            if(k == key) return it;

            it++;
        }

        return it;
    }
    void put(int key, int value) {
        int idx = getIdx(key);

        auto it = findKey(key, idx);

        if(it == buckets[idx].end()) {
            buckets[idx].push_back({key, value});
        }
        else {
            (*it).second = value;
        }
    }
    
    int get(int key) {
        int idx = getIdx(key);

        auto it = findKey(key, idx);

        if(it != buckets[idx].end()) {
            return (*it).second;
        }
        else return -1;
    }
    
    void remove(int key) {
        int idx = getIdx(key);

        auto it = findKey(key, idx);

        if(it != buckets[idx].end()) {
            buckets[idx].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */