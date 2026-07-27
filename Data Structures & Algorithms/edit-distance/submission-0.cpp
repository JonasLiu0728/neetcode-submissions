class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> old(n+1,0);
        vector<int> fresh(n+1,0);
        for(int i=0;i<=n;i++){
            old[i] = i;
        }
        fresh[0] = 1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                fresh[0] = old[0]+1;
                if( word1[i-1]==word2[j-1] ){
                    fresh[j] = old[j-1];
                }
                else{
                    fresh[j] = min( {old[j-1]+1,old[j]+1,fresh[j-1]+1} );
                }
            }
            swap(old,fresh);
        }
        return old[n];
    }
};