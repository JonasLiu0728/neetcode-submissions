class Solution {
public:
    void generate(int n,string& P,int left_brace, int right_brace,vector<string>& result){
        if(P.size()==2*n){
            result.push_back(P);
            return;
        }
        if(left_brace<n){ //如果左邊還不夠，再往下加下去
            P.push_back('(');
            generate(n, P , left_brace+1 , right_brace , result );
            P.pop_back();
        }
        if(left_brace>right_brace){
            P.push_back(')');
            generate(n, P , left_brace , right_brace+1 , result );
            P.pop_back();
        } 
    }
    vector<string> generateParenthesis(int n) {
        string P = "(";
        vector<string> result;
        generate(n,P,1,0,result);
        return result;
    }
};