class Solution {
public:
    void output(vector<vector<int>>& table){
        for(int i=0;i<table.size();i++){
            for(int j=0;j<table.size();j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int countSubstrings(string s) {
        int result = 0;
        int length = s.size();
        vector<vector<bool>> table(s.size(),vector<bool>(s.size(),0));
        for(int j=0;j<s.size()-1;j++){
            table[j+1][j] = 1;
        }
        //output(table);
        for(int d=0;d<length;d++){
            for(int i=0;i+d<length;i++){
                int j = i+d;
                if(d==0){
                    table[i][j] = 1;
                    result++;
                    continue;
                }
                if( table[i+1][j-1]==1 && s[i]==s[j] ){
                    table[i][j] = 1;
                    result++;
                }
            }
        }
        return result;
    }
};