class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int s = nums.size();
        
        vector<int> res;
        
        int start = s - 1;
        int ans = INT_MIN;
        
        sort(nums.begin(), nums.end());
        
        vector<pair<int, int>> dp(s, {1, -1});
        
        for (int i = s - 1; i >= 0; i--) {
            int temp = 1;
            for (int j = i + 1; j < s; j++) {
                if (!(nums[j] % nums[i])) {
                    if (dp[j].first + 1 > dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = j;
                    }
                }
            }
            
            if (dp[i].first > ans) {
                start = i;
                ans = dp[i].first;
            }
        }
        
        while (start != -1) {
            res.push_back(nums[start]);
            start = dp[start].second;
        }
        
        return res;
    }
};
