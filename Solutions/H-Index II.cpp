class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        
        if (n == 0) {
            return n;
        }
        
        int l = 0;
        int h = n - 1;
        
        int mid;
        
        while (l <= h) {
            
            int mid = (h - l) / 2 + l;
            
            if(citations[mid] < n - mid) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return n - l;
    }
};
