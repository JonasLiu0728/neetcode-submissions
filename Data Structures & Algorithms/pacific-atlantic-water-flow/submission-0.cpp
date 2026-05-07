class Solution {
public:
    bool can_climb( int i,int j,int m, int n ,vector<vector<int>>& grid){
        if( m<0 || n<0 || m>grid.size()-1 || n>grid[0].size()-1 || grid[i][j]>grid[m][n] ) return false;
        return true;
    }
    void bfs(int i,int j,set< vector<int> >& ocean ,vector<vector<int>>& grid){
        if( ocean.contains({i,j}) ){
            return;
        }
        ocean.insert( {i,j} );
        if( can_climb(i,j,i-1,j,grid) ){
            bfs(i-1,j,ocean,grid);
        }
        if( can_climb(i,j,i,j-1,grid) ){
            bfs(i,j-1,ocean,grid);
        }
        if( can_climb(i,j,i+1,j,grid) ){
            bfs(i+1,j,ocean,grid);
        }
        if( can_climb(i,j,i,j+1,grid) ){
            bfs(i,j+1,ocean,grid);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set< vector<int> > pacific;
        set< vector<int> > atlantic;
        vector< vector<int> > result;
        int m = heights.size();
        int n = heights[0].size();

        for(int i=0;i<m;i++){
            bfs(i,0,pacific,heights);
            bfs(i,n-1,atlantic,heights);
        }
        for(int i=0;i<n;i++){
            bfs(0,i,pacific,heights);
            bfs(m-1,i,atlantic,heights);
        }
        set_intersection(
            pacific.begin(), pacific.end(),   // 第一個集合的範圍
            atlantic.begin(), atlantic.end(), // 第二個集合的範圍
            back_inserter(result)        // 輸出目標，使用 back_inserter 自動處理 push_back
        );
        return result;
    }
};