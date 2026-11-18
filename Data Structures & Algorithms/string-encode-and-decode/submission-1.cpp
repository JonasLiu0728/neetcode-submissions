#include <string>
class Solution {
public:
    string length_of(string str){
        string result;
        if(str.size()<10){
            result = "00"+to_string(str.size());
        }
        else if(str.size()>=10&&str.size()<100){
            result = "0"+to_string(str.size());
        }
        else{
            result = to_string(str.size());
        }
        return result;
    }
    string encode(vector<string>& strs) {
        string result;
        for(int i=0;i<strs.size();i++){
            string temp;
            temp += length_of(strs[i]);
            temp += strs[i];
            result += temp;
        }
        return result;
    }

    vector<string> decode(string s) {
        cout<<s<<endl;
        vector<string> result;
        for(int i=0;i<s.size();i++){
            int size = (s[i]-48)*100 + (s[i+1]-48)*10 + (s[i+2]-48);
            if( i+2<s.size()-1) result.push_back( s.substr(i+3,size) );
            else if( i+2==s.size()-1) result.push_back("");
            i += (2+size);
        }
        return result;
    }
};
