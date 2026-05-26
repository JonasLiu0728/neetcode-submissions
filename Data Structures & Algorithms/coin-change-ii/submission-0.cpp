class Solution {
public:
    void output(vector< vector<int> >& table){
        for(int i = 0; i < table.size(); i++){
            for(int j = 0; j < table[i].size(); j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int exchange(vector<vector<long>>& table,int i,int j,int coin){
        int index = j;
        
        long result = table[i-1][index];
        
        if( index-coin >= 0 ) result += table[i][index-coin];
        return result;
    }
    int change(int amount, vector<int>& coins) {
        //sort(coins.begin(),coins.end());
        vector<vector<long>> table(coins.size(),vector<long>(amount+1));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) table[0][i] = 1;
            else table[0][i] = 0;
        }
        for(int i=0;i<coins.size();i++){
            table[i][0] = 1;
        }
        //output(table);
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                //cout<<"i/j/coin : "<<i<<"/"<<j<<"/"<<coins[i]<<endl;
                table[i][j] = exchange(table,i,j,coins[i]);
                //output(table);
            }
        }
        return table[coins.size()-1][amount];
    }
};