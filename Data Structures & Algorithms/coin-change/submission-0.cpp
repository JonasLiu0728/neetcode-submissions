class Solution {
public:
    void output(vector<int>& table){
        for(int i=0;i<table.size();i++){
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> table(amount+1,0);
        if(amount == 0) return 0;
        else if( amount<coins[0] ) return -1;
        for(int i=1;i<coins[0];i++) table[i] = -1;
        table[ coins[0] ] = 1;

        for(int i=coins[0]+1;i<table.size();i++){
            int min = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i==coins[j]){
                    min = 1;
                    break;
                } 
                if( i-coins[j]<0) break;
                else if(table[ i-coins[j] ] == -1 ) continue; //換不了
                if( table[ i-coins[j] ]+1 < min ) min = table[ i-coins[j] ]+1;
            }
            if(min == INT_MAX) table[i] = -1; //代表無法湊出
            else table[i] = min;
            //output(table);
        }
        return table[amount];
    }
};