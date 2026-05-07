class Solution {
public:
    void output(vector<string>& result){
        cout<<"================================="<<endl;
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result.size();j++){
                cout<<result[i][j];
            }
            cout<<endl;
        }
        cout<<"================================="<<endl;
    }
    bool is_valid(vector<string>& table,int row,int col){
        //for(int i=0;i<table.size();i++){
        //    if(table[row][i]=='Q') return false;
        //}
        for(int i=0;i<table.size();i++){
            if(table[i][col]=='Q') return false;
        }
        // 2. 檢查左上對角線
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (table[i][j] == 'Q') return false;
        }

        // 3. 檢查右上對角線
        for (int i = row - 1, j = col + 1; i >= 0 && j < table.size(); i--, j++) {
            if (table[i][j] == 'Q') return false;
        }
        return true;
    }
    void put(vector<string>& table, int row, int col) {
        table[row][col] = 'Q';
    }
    void remove(vector<string>& table, int row, int col) {
        table[row][col] = '.';
    }
    void backtracking(vector<vector<string>>& result,vector<string>& table, int row, int n){
        if( row==n ){ //全部都放完了
            result.push_back(table);
            return;
        }
        for(int i=0;i<table.size();i++){
            if( is_valid(table,row,i) ){
                put(table,row,i);
                backtracking(result,table,row+1,n);
                remove(table,row,i);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> table(n,string(n,'.'));
        backtracking(result,table,0,n);
        return result;
    }
};