class Solution {
public:
    void output_board(vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        cout<<"=============================="<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool dfs(vector<vector<char>>& board,string& word,int i,int j,int index){
        if(index==word.length()){
            return true;
        }
        if( i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[index]!=board[i][j]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*'; // X代表走訪過了
        bool found = (
                dfs(board,word,i+1,j,index+1) ||
                dfs(board,word,i-1,j,index+1) ||
                dfs(board,word,i,j+1,index+1) ||
                dfs(board,word,i,j-1,index+1)
                );
        board[i][j] = temp; //回復原本的狀態 很重要
        return found;
    }
    //方向
    //初始搜尋 0 (第一個字)
    //上往下 1
    //下往上 2
    //左往右 3
    //右往左 4
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int total_size = m*n;
        bool result=false;
        for(int i=0;i<total_size;i++){
            if( board[i/n][i%n]==word[0] && !result){ //如果已經找到就不要再找了
                result = dfs(board,word,i/n,i%n,0);
            }
        }
        return result;
    }
};