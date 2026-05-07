class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        // 1. 基底情況 (Base Case): 
        // 由於我們在進入遞迴前會檢查 '1'，此處僅處理已被標記或水域的情況
        if (grid[i][j] == '0' || grid[i][j] == '*') return false;

        // 2. 標記處理 (State Change)
        grid[i][j] = '*';

        int m = grid.size();
        int n = grid[0].size();

        // 3. 鄰域探索 (Neighborhood Exploration)
        // 必須先進行短路求值 (Short-circuit evaluation) 的邊界檢查，再存取陣列
        if (i + 1 < m  && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (j + 1 < n  && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // 只有遇到未訪問的陸地才啟動 DFS，確保 result 增加的次數等於島嶼數
                if (grid[i][j] == '1') {
                    result += dfs(grid, i, j);
                }
            }
        }
        return result;
    }
};