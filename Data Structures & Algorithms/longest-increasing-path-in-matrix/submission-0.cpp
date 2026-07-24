class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != 0) return memo[i][j];
        
        // At least itself
        int best = 1;
        // Four direction
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            
            if( ni<0 || nj<0 || ni>=matrix.size() || nj>=matrix[0].size() )
                continue;
            
            if( matrix[ni][nj] > matrix[i][j] )
                best = max(best,dfs(matrix,memo,ni,nj)+1);
        }

        memo[i][j] = best;
        return best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int MAX = INT_MIN;
        vector<vector<int>> memo(m,vector<int>(n,0)); //從自己出發 最長可以走到多長

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp = dfs(matrix,memo,i,j);
                if(temp>MAX) MAX = temp;
            }
        }

        return MAX;
    }
};