class Solution {
public:
    void output(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }    
            cout<<endl;
        }
        cout<<endl;
    }
    void expand(int i, int j ,vector<pair<int,int>>& new_rotten,vector<vector<int>>& grid){
        i = i-1;
        j = j;
        if( i>=0 && j>=0 && i<=grid.size()-1 && j<=grid[0].size()-1 && grid[i][j]==1){
            grid[i][j] = 2;
            new_rotten.push_back({i,j});
        }
        i = i+1;
        j = j-1;
        if( i>=0 && j>=0 && i<=grid.size()-1 && j<=grid[0].size()-1 && grid[i][j]==1){
            grid[i][j] = 2;
            new_rotten.push_back({i,j});
        }
        i = i+1;
        j = j+1;
        if( i>=0 && j>=0 && i<=grid.size()-1 && j<=grid[0].size()-1 && grid[i][j]==1){
            grid[i][j] = 2;
            new_rotten.push_back({i,j});
        }
        i = i-1;
        j = j+1;
        if( i>=0 && j>=0 && i<=grid.size()-1 && j<=grid[0].size()-1 && grid[i][j]==1){
            grid[i][j] = 2;
            new_rotten.push_back({i,j});
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> rotten;
        int apple_num = 0;
        
        int time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2||grid[i][j]==1){
                    apple_num++;
                }
                if(grid[i][j]==2){
                    rotten.push_back({i,j});
                }
            }
        }
        int rotten_num=rotten.size();
        while(1){
            //針對每個壞掉的蘋果擴散
            vector<pair<int,int>> new_rotten;
            for(pair<int,int> temp : rotten){
                //cout<<temp.first<<" "<<temp.second<<endl;
                expand( temp.first , temp.second , new_rotten , grid);
            }
            rotten_num+=new_rotten.size();
            if(new_rotten.size()==0) break;
            rotten = move(new_rotten);
            time++;
        }
        if( rotten_num < apple_num ) return -1;
        return time;
    }
};