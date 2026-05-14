class Solution {
public:
    void output(vector<bool>& table){
        for(int i=0;i<table.size();i++){
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }
    bool append(string s,int i,int j,string word){
        return s.compare(i, j-i+1, word) == 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        s.insert(0, "$");
        vector<bool> table(s.size());
        table[0] = true;
        for(int i=0;i<table.size();i++){
            //output(table);
            for(string word : wordDict){ 
                if( i-(int)word.size()>=0 && table[i-word.size()]==true && append(s,i-word.size()+1,i,word)){
                    table[i] = true;
                    break;
                }
            }
        }
        //output(table);
        return table[s.size()-1]; 
    }
};