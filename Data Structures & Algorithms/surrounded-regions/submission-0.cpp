class Solution {
public:
    void output(vector<vector<char>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }    
            cout<<endl;
        }
        cout<<endl;
    }
    bool can_climb(int m, int n ,vector<vector<char>>& grid){
        if( m<0 || n<0 || m>grid.size()-1 || n>grid[0].size()-1 || grid[m][n]=='X' || grid[m][n]=='#') return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<char>>& grid){
        if( grid[i][j]=='X'){
            return;
        }
        
        grid[i][j] = '#';

        if( can_climb(i-1,j,grid) ){
            bfs(i-1,j,grid);
        }
        if( can_climb(i,j-1,grid) ){
            bfs(i,j-1,grid);
        }
        if( can_climb(i+1,j,grid) ){
            bfs(i+1,j,grid);
        }
        if( can_climb(i,j+1,grid) ){
            bfs(i,j+1,grid);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board.empty() ? 0 : board[0].size();

        for(int i=0;i<rows;i++){
            //output(board);
            if(board[i][0]=='O') bfs(i,0,board);
            if(board[i][cols-1]=='O') bfs(i,cols-1,board);
        }
        for(int j=0;j<cols;j++){
            //output(board);
            if(board[0][j]=='O') bfs(0,j,board);
            if(board[rows-1][j]=='O') bfs(rows-1,j,board);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if( board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};