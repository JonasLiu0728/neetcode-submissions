class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool can_flow(int i,int j,vector<vector<int>>& status, vector<vector<int>>& grid){ //判斷能不挊
        if( i<0 || j<0 || i>=grid.size() || j>= grid.size() || status[i][j] == 0){
            return 0;
        }
        return 1;
    }
    void up_flow(vector<vector<int>>& status, vector<vector<vector<int>>>& table,int time){ //漲水位了
        for(vector<int> temp : table[time]){
            status[ temp[0] ][ temp[1] ] = 1; //開啟
        }
    }
    bool bfs(vector<vector<int>>& grid,vector<vector<int>>& status){ //回傳時間
        vector<vector<int>> visited(grid.size(),vector<int>(grid.size(),0));
        queue<vector<int>> Q;
        if( can_flow(0,0,status,grid) ) Q.push({0,0});
        while(!Q.empty()){
            vector<int> curr = Q.front();
            Q.pop();
            if(curr[0]==grid.size()-1 && curr[1]==grid.size()-1 ) return true;
            //往四面八方bfs
            int i = curr[0];
            int j = curr[1];
            //轉換方向
            for (auto& d : dirs) {
                int nr = i + d.first;
                int nc = j + d.second;

                // 邊界檢查與條件判定
                if (can_flow(nr,nc,status,grid) && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    Q.push({nr, nc});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> status(grid.size(),vector<int>(grid.size(),0));
        vector<vector<vector<int>>> table(2500); //儲存每個水位的高度
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                table[grid[i][j]].push_back({i,j});
            }
        }

        for(int i=0;i<2500;i++){
            up_flow(status,table,i);
            if(bfs(grid,status)) return i;
        }
        return -1;
    }
};