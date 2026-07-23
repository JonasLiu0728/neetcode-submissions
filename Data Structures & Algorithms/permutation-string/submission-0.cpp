class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        vector<int> s1_table(26,0);
        for(int i=0;i<s1.size();i++){
            s1_table[s1[i]-97]++;
        }

        vector<int> table(26,0);
        for(int i=0;i<s1.size();i++){
            table[s2[i]-97]++;
        }
        // Two string has same length
        
        //if( s1.size() == s2.size() ) return s1_table == table; (這句是多餘的)
        
        // Sliding window比較
        if( s1_table == table ) return true;
        for(int i=1;i<=s2.size()-s1.size();i++){
            table[s2[i-1]-97]--;
            table[s2[i+s1.size()-1]-97]++;
            if( s1_table == table ) return true;
        }
        return false;
    }
};