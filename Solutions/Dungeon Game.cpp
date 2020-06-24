class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int l = dungeon.size();
        int w = dungeon[0].size();
        
        vector<vector<int>> hp(l + 1, vector<int>(w + 1, INT_MAX));
        
        hp[l][w-1] = hp[l-1][w] = 1;
        
        for (int x = l-1; x >= 0; --x) {
            for (int y = w-1; y >= 0; --y) {
                hp[x][y] = max(1, min(hp[x + 1][y], hp[x][y + 1]) - dungeon[x][y]);
            }
        }
        
        return hp[0][0];
    }
};
