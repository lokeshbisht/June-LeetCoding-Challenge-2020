class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int totalCost = 0;
        
        for (auto i : costs) {
            totalCost += i[0];
        }
        
        vector<int> diff;
        
        for (auto i : costs) {
            diff.push_back(i[1] - i[0]);
        }
        
        sort(diff.begin(), diff.end());
        
        for (int i = 0; i < costs.size()/2; i++) {
            totalCost += diff[i];
        }
        
        return totalCost;
    }
};
