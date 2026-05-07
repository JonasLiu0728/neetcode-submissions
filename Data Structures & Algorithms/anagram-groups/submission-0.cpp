class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int length = strs.size();
        vector< pair<string,string> > table;

        for(int i=0;i<length;i++){ //i遍歷所有字串
            table.push_back ( make_pair(string(26,'\0'),strs[i]) );
            for(int j=0;j<strs[i].size();j++){ // j遍歷每個字串裡面所有字元
                table[i].first[ strs[i][j]-97 ]++;
            }
        }
        sort(table.begin(),table.end());

        vector<vector<string>> result;
        for(int i=0;i<length;i++){
            vector<string> temp;
            temp.push_back(table[i].second);
            while( i+1<length && table[i].first == table[i+1].first){
                i++;
                temp.push_back(table[i].second);
            }
            result.push_back(temp);
        }
        
        return result;
    }
};