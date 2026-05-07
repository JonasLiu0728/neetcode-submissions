class stats{
public:
    vector<pair<int,char>> table;
    int char_num=0;
    stats();
    void add(char t);
    void remove(char t);
    int diff();//需要的替換次數
};
stats::stats(){
    table.reserve(26);
    for (int i = 0; i < 26; i++) {
        table.push_back({0, static_cast<char>('A' + i)});
    }
    char_num=0;
}
void stats::add(char t){
    table[t-'A'].first++;
    char_num++;
}
void stats::remove(char t){
    table[t-'A'].first--;
    char_num--;
}
int stats::diff(){
    int max=0;
    for(int i=0;i<table.size();i++){
        if( table[i].first > max ) max = table[i].first;
    }
    return char_num - max;
}
class Solution {
public:
    int characterReplacement(string s, int k) {
        int result=1;
        int low=0;//window的第一個字
        int high=0;//window最後一個字母的下一個
        stats STATS;
        //有K次機會換字母，所以window裡面除了出現最多次的以外，只能有length-k個
        
        for(int high=0;high<s.size();high++){
            STATS.add(s[high]);
            int difference = STATS.diff();
            //合法化視窗
            while( difference>k ){
                STATS.remove(s[low]);
                low++;
                difference = STATS.diff();
            }
            int window_size = high-low+1;
            if( window_size > result ) result = window_size;
        }

        return result;
    }
};