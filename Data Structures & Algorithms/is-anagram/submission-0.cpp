class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> s_table(26,0);
        vector<int> t_table(26,0);
        for(int i=0;i<s.size();i++){
            s_table[s[i]-97]++;
            t_table[t[i]-97]++;
        }
        if(s_table==t_table) return true;
        return false;
    }
};