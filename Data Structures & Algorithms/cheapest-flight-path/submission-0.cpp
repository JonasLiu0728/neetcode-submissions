class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman ford做k步
        vector<vector<long long>> dis(2,vector<long long>(n,INT_MAX));
        dis[0][src] = dis[1][src] = 0;

        for(int i=0;i<k+1;i++){
            for(int j=0;j<n;j++){
                dis[0][j] = dis[1][j];
            }
            for(int j=0;j<flights.size();j++){
                int u = flights[j][0];
                int v = flights[j][1];
                int length = flights[j][2];
                if( dis[0][u] != INT_MAX && dis[1][v] > dis[0][u]+length ){
                    dis[1][v] = dis[0][u]+length;
                }
            }
        }
        if(dis[1][dst]==INT_MAX) return -1;
        return dis[1][dst];
    }
};