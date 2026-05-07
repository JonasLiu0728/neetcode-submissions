class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        bool result = false;
        vector< vector<int> > list(numCourses); 
        vector<int> in_degree(numCourses, 0);
        for(int i=0;i<pre.size();i++){
            list[ pre[i][1] ].push_back(pre[i][0]);
            in_degree[ pre[i][0] ]++; 
        }
        queue<int> Q;
        
        
        for(int i=0;i<numCourses;i++){
            if(in_degree[i] == 0){
                Q.push(i);
                result = true;//暫時可能
            }
        }
        if( !result ) return result;
        
        //開始做BFS
        int processed_count = 0;
        int temp; //current正在處理的點
        while( !Q.empty() ){
            temp = Q.front();
            Q.pop();
            processed_count++;
            for(int i=0;i<list[temp].size();i++){
                in_degree[ list[temp][i] ]--;
                if( !in_degree[ list[temp][i] ]) Q.push(list[temp][i]);
            }
        }
        if( processed_count == numCourses) return true;
        else return false;
        return result;
    }
};