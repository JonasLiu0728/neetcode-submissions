class Solution {
public:
    void output(vector<int>& table){
        for(int i=0;i<table.size();i++){
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }
    int numDistinct(string s, string t) {
        vector<unsigned int> table(t.size(),0);
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            vector<unsigned int> add(t.size(),0);
            if( curr==t[0] ) add[0]++; //第一個一樣
            for(int j=1;j<t.size();j++){
                
                if( curr==t[j] ){
                    add[j] = table[j-1];
                }

            }
            for(int j=0;j<t.size();j++){
                //cout<<table[j]<<" "<<add[j]<<endl;
                table[j] += add[j];
            }
        }
        return table[t.size()-1];
    }
};