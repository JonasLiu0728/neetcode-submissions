class Solution {
public:
    struct Node{
        char alphabat;
        vector<Node*> neighbors;
    };
    bool first_diff(string A,string B,unordered_map<char,unordered_set<char>>& G,unordered_map<char,int>& in_degree){
        
        int length = min(A.size(),B.size());
        for(int i=0;i<length;i++){
            if(A[i]!=B[i]){ //找到一個關係
                if (G[A[i]].find(B[i]) == G[A[i]].end()){
                    G[A[i]].insert(B[i]);
                    in_degree[B[i]]++;
                }
                return true;
            }
        }
        if(A.size()>B.size()) return false;
        return true;        
    }
    string bfs(unordered_map<char,unordered_set<char>>& G,unordered_map<char,int>& in_degree){
        queue<char> Q;
        string result;
        for(const auto& [node, degree] : in_degree){
            if(degree==0) Q.push(node);
        }

        while(!Q.empty()){
            char curr = Q.front();
            Q.pop();
            result += curr;

            for(char neighbors : G[curr]){
                in_degree[neighbors]--;
                if(in_degree[neighbors]==0) Q.push(neighbors);
            }
        }

        if( in_degree.size() != result.size() ) return {};
        else return result;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> G;
        unordered_map<char,int> in_degree;
        for (const string& word : words) {
            for (char c : word) {
                G[c];           // 確保節點存在於圖中
                in_degree[c] = 0;   // 明確宣告所有節點的初始入度為 0
            }
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(first_diff(words[i],words[j],G,in_degree) == false) return {}; //抓到invalid input
            }
        }
        return bfs(G,in_degree);
    }
};






