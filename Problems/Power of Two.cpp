class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n == 0) {
            return false;
            
        }
        if (n == 1) {
            return true;
            
        }
        bool poss = true;
        
        while (n) {
            if (n != 1 && n % 2 != 0) {
                poss = false;
                break;
            }
            n /= 2;
        }
        
        return poss;
    }
};
