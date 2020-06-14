class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pos;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                pos = i;
                break;
            } else if (nums[i] > target) {
                pos = i;
                break;
            }
        }
        
        return pos;
    }
};
