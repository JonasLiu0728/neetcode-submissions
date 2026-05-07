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
    void dfs(vector<vector<int>>& grid,int i,int j,int& temp){
        if( i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 || grid[i][j]==0 ) return;

        char c = grid[i][j];
        grid[i][j] = -1;

        //dfs
        dfs(grid,i+1,j,temp);
        dfs(grid,i,j+1,temp);
        dfs(grid,i-1,j,temp);
        dfs(grid,i,j-1,temp);
        
        temp++;
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int temp=INT_MIN;
        int max=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp = 0;
                dfs(grid,i,j,temp);
                if( temp>=max ) max = temp;
            }    
        }
        return max;
    }
};