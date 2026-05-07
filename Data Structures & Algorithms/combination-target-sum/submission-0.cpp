class Solution {
public:
    void backtrack(const vector<int>& candidates, int target, int current_sum, int start_index, vector<int>& path, vector<vector<int>>& result){
        if(current_sum == target){
            result.push_back(path);
            return;
        }
        else{
            for(int i=start_index;i<candidates.size();i++){
                if(current_sum+candidates[i]>target) continue;
                path.push_back(candidates[i]);
                backtrack(candidates,target,current_sum+candidates[i],i,path,result);
                path.pop_back(); //撤回選擇
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path; //current path
        backtrack(candidates,target,0,0,path,result);
        return result;
    }
};