class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> pq; // {累積距離,node} 
        vector<vector<pii>> list(n+1); // adjacnecy list {neighbor,weight}
        
        //initialize adjacency list
        for(int i = 0; i < times.size(); i++){
            list[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        //Start Dijkstra
        pq.push( {0,k} );

        while(!pq.empty()){
            int dis = pq.top().first;
            int source = pq.top().second;
            pq.pop();
            if(dis > distance[source]) continue; //剛剛從 pq裡面拿出來的 distance可能是舊的，有更短的路，所以這條路就不用了
            for(pii neighbors : list[source]){
                int next_node = neighbors.first;
                int weight = neighbors.second;
                if( dis+weight < distance[next_node] ){ //Relaxation
                    distance[next_node] = dis+weight;
                    pq.push({distance[next_node],next_node});
                }
            }
        }
        int result = INT_MIN;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;
            if(distance[i]>result) result = distance[i];
        }
        return result;
    }
};