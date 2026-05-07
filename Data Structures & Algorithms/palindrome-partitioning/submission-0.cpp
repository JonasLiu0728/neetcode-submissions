class Solution {
public:
    bool is_palindrome(const string& s,int a,int b){ 
        int length = (b-a)/2 +1 ;
        for(int i=0;i<length;i++){
            if(s[a+i]!=s[b-i]) return false;
        }
        return true;
    }
    void backtracking(const string& s,int index,vector<string>& partition,vector<vector<string>>& result){ // index:第一個比較的index
        if(index == s.size()){ //整個走完了
            result.push_back(partition);
            return;
        }

        for(int i=index;i<s.size();i++){
            if( is_palindrome(s,index,i) ){ //const parameter 傳給function 那個function 一樣要是 const
                //cout<<s.substr(index, i - index + 1)<<"是 palindrome"<<endl;
                partition.push_back(s.substr(index, i - index + 1));
                backtracking(s,i+1,partition,result);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector< vector<string> > result;
        vector<string> temp;
        backtracking(s,0,temp,result);
        return result;
    }
};