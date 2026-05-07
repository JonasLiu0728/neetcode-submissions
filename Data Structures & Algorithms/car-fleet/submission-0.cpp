class Solution {
public:
    bool match(double target,pair<int,int> front, pair<int,int> back){
        if(back.first == -1) return 1;//dummy 預設追得上的
        double front_arr = (double) ( target-front.first ) / front.second ;
        double back_arr = (double) ( target-back.first ) / back.second ;
        return ( front_arr >= back_arr ) ? /*追得上*/1 : /*追不上*/0;
    }
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int,int>> table;
        
        for(int i=0;i<pos.size();i++){
            table.push_back( {pos[i],speed[i]} );
        }

        sort( table.rbegin(), table.rend() );
        //push一個dummy 方便比較
        int result = 0;
        int fleet = 0;
        table.push_back( {-1,-1} );
        for( int i=0;i<table.size()-1;i++ ){
            int head = i;
            while( i<table.size()-1 && match(target,table[head],table[i+1]) ){
                //有match 先存到stack
                i++;
            }
            result++;
        }
        return result;
    }
};