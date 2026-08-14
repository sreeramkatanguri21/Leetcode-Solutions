class NumberContainers {
public:
    unordered_map<int, set<int>> list; // val -> {indexes}
    unordered_map<int, int> mpp; // index -> val
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpp.count(index)) {
            int prev = mpp[index];
            list[prev].erase(index);
        }
        list[number].insert(index);
        mpp[index] = number;
    }
    
    int find(int number) {
        if(!list[number].empty()) {
            return *list[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */