class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }   
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'L') board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
        
        board[x][y] = 'L';
        
        for (int i = 0; i < dir.size(); ++i) {
            
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            
            if (xx >= 0 && xx < m && yy > 0 && yy < n && board[xx][yy] == 'O') {
                dfs(board, xx, yy);
            }
        }
    }
};
