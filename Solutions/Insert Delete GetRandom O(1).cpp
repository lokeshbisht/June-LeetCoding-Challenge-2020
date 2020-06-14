class RandomizedSet {
public:
    
    unordered_set<int> values;
    
    RandomizedSet() {
        
    }
    
    
    bool insert(int val) {
        
        return (values.insert(val)).second;
    }
    
    
    bool remove(int val) {
        
        return values.erase(val);
    }
    
    
    int getRandom() {
        
        return *next(values.begin(), rand() % values.size());
    }
};
