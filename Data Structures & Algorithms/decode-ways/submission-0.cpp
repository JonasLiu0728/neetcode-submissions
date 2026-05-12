class Solution {
public:
    bool valid(char A,char B){
        if( A>'2' || A=='0' ) return false;
        else if(A=='2'){
            if(B>'6') return false;
        }
        return true;
    }
    bool initialize(string& s,vector<long long>& table){
        if( s[0]=='0' ) return false; //leading zero
        
        if(s[0]=='0' && s[1]=='0'){
            table[0] = table[1] = 0;
        }
        else if(s[0]=='0' && s[1]!='0'){
            table[0] = 0;
            table[1] = 1;
        }
        else if(s[0]!='0' && s[1]=='0'){
            if(s[0]=='1'||s[0]=='2'){
                table[0] = 0;
                table[1] = 1;
            }
            else{
                return false;
            }
        }
        else if(s[0]!='0' && s[1]!='0'){
            if( valid(s[0],s[1]) ){
                table[0] = 1;
                table[1] = 2;
            }
            else{
                table[0] = 1;
                table[1] = 1;
            }
        }
        return true;
    }
    int numDecodings(string s) {
        vector<long long> table(s.size(),0);
        if( s.size()==1 && s[0]!='0') return 1;
        if(!initialize(s,table)) return 0;
        for(int i=2;i<s.size();i++){
            if(s[i]=='0'){
                if(s[i-1]>'2'||s[i-1]<'1'){
                    return 0;
                } 
                else table[i] = table[i-2];
            }
            else if(valid(s[i-1],s[i])){ 
                table[i] = table[i-1]+table[i-2];
            }
            else{
                table[i] = table[i-1];
            }
            //for(int j=0;j<table.size();j++){
            //    cout<<table[j]<<" ";
            //}
            //cout<<endl;
        }
        return table[s.size()-1];
    }
};