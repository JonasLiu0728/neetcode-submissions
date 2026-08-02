class Solution {
public:
    void output(vector< pair<int,int> >& table){
        for(int i=0;i<table.size();i++){
            cout<<table[i].first<<" : "<<table[i].second<<endl;
        }
        cout<<endl;
    }
    bool deduct(vector< pair<int,int> >& table,int groupSize, int pos ){
        int number = table[pos].second;
        for(int i=pos;i<pos+groupSize-1;i++){
            if(i+1>=table.size()) return false; //超出邊界
            if( table[i].first+1 != table[i+1].first ) return false;

        }
        for(int i=pos;i<pos+groupSize;i++){
            if(i>=table.size()) return false; //超出邊界
            table[i].second -= number;
            if(table[i].second<0) return false;
        }
        return true;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector< pair<int,int> > table;
        if(hand.size()%groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            if( i==0 || hand[i]!=hand[i-1] ){
                table.push_back({hand[i],1});
            }
            else{
                (table.end() - 1)->second++;
            }
        }
        //output(table);
        for(int i=0;i<table.size();i++){
            if(table[i].second==0) continue;
            else{
                if( deduct(table,groupSize,i)==0 ) return false;
                
            }
        }
        //output(table);
        return 1;
    }
};