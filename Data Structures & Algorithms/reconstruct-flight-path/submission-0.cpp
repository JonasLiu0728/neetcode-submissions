class Solution {
public:
    unordered_map<string, multiset<string>> edges;
    vector<string> result;
    void dfs(string start){
        while(!edges[start].empty()){
            string temp = *edges[start].begin();
            edges[start].erase(edges[start].begin());
            dfs(temp);
        }
        result.push_back( start );
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            edges[ tickets[i][0] ].insert(tickets[i][1]);
        }
        string start = "JFK";
        dfs(start);
        //剛剛是反著放 要正著放回來
        reverse(result.begin(), result.end());
        return result;
    }
};