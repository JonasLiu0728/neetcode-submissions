class Solution {
public:
    bool valid_box(vector<vector<char>>& board,vector<short>& row,vector<short>& col,int r,int c){
        short box = 0;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                int i = r+k;
                int j = c+l;
                if( board[i][j]=='.' ) continue;
                int curr = int(board[i][j])-48;
                
                int pow_curr = 1<<curr;
                // Judge if the board are valid
                if( box == (box|pow_curr) ){
                    return false;
                }
                box |= pow_curr;
                // Judge if row and column are valid
                if(row[i] == (row[i]|pow_curr) ){
                    return false; //重複數字
                }
                row[i] |= pow_curr;
                if(col[j] == (col[j]|pow_curr) ){
                    return false; //重複數字
                }
                col[j] |= pow_curr;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<short> col(9,0);
        vector<short> row(9,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if( !valid_box(board,row,col,i*3,j*3) ) return false;
            }
        }
        return true;
    }
};