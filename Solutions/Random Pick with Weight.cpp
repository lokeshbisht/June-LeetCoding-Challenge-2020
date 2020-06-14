class Solution {
public:
    
    vector<int> v;
    
    Solution(vector<int>& w) {
        for (auto i : w) {
            v.push_back(v.empty() ? i : (i + v.back()));        
        }
        
    }
    
    int pickIndex() {
        
        int r = rand() % v.back();
        
        auto itor = upper_bound(v.begin(), v.end(), r);
        
        return itor - v.begin();
        
    }
};

