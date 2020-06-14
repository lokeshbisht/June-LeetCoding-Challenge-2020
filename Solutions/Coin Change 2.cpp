class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int arr[amount + 1];
        
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;
        
        for (auto i : coins) {
            for (int j = i; j <= amount; j++) {
                arr[j] += arr[j - i];
            }
        }
        
        return arr[amount];
    }
};
