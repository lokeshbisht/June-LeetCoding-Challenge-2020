class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        int curr = 0;
        
        while (curr <= end) {
            if (nums[curr] == 2) {
                swap(nums[curr], nums[end]);
                
                end--;
            } else if (nums[curr] == 0) {
                swap(nums[start], nums[curr]);
                
                start++;
                curr++;
            } else {
                curr++;
            }
            
        }
        
    }
};
