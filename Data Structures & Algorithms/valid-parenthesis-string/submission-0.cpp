#include <cstring>
using namespace std;
class Solution {
public:
    int memo[101][101];
    bool valid(int left,int i,string& s){
        if(left<0||left>s.size()-i) return false;
        
        if(i==s.size()){
            if(left!=0) return false;
            else return true;
        }

        // If this state was computed before
        if (memo[i][left] != -1) {
            return memo[i][left];
        }
        int ans;
        if(s[i]=='('){
            ans = valid(left+1,i+1,s);
        }
        else if(s[i]==')'){
            ans = valid(left-1,i+1,s);
        }
        // 最後一種一定是*
        else ans = valid(left+1,i+1,s) || valid(left-1,i+1,s) || valid(left,i+1,s);
        memo[i][left] = ans;
        return ans;
    }
    bool checkValidString(string s) {
        memset(memo, -1, sizeof(memo));
        return valid(0,0,s);
    }
};