class Solution {
public:
    int dist(int i,int j,vector<vector<int>>& points){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    int find(int u,vector<int>& parent){
        if(parent[u]==u) return u;
        parent[u] = find(parent[u],parent);
        return parent[u];
    } 
    bool unite(int u,int v,vector<int>& parent){
        int a = find(u,parent);
        int b = find(v,parent);
        if( a==b ) return false; //已經在同一個cluster了
        parent[b] = a; //把兩個node的parent設定成一樣
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> parent(points.size());
        vector< vector<int> > edge;
        for(int i=0;i<points.size();i++){
            parent[i] = i;
            for(int j=i+1;j<points.size();j++){
                edge.push_back({ dist(i,j,points),i,j });
            }
        }
        sort(edge.begin(),edge.end());
        int result = 0;
        int connected = 1;
        for(int i=0;i<edge.size();i++){
            //看看兩點會不會形成cycle
            if(connected == points.size()) break;
            if(unite(edge[i][1],edge[i][2],parent)){ //可以合併
                result += edge[i][0];
                connected++;
            }
        }
        return result;
    }
};