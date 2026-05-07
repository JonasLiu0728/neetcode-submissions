class Solution {
public:
    void backtrack(const vector<pair<int,int>>& table, int target, int current_sum, 
                    int pick_index, int pick_num, vector<int>& path, vector<vector<int>>& result){

        if(current_sum == target){
            result.push_back(path);
            return;
        }
        else if(current_sum > target){
            return;
        }
        else{
            //選擇跟自己一樣的數字(如果可以的話)
            if(pick_num+1<=table[pick_index].second){ 
                path.push_back(table[pick_index].first);
                backtrack(table,target,current_sum+table[pick_index].first,pick_index,pick_num+1,path,result);
                path.pop_back(); //撤回選擇
            }
            //選擇下一個數字
            for(int i=pick_index+1;i<table.size();i++){
                if(current_sum+table[i].first>target) break; //如果這個數字放不下 下一個一定放不下
                path.push_back(table[i].first);
                backtrack(table,target,current_sum+table[i].first,i,1,path,result);
                path.pop_back(); //撤回選擇
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>> result;
        //vector<pair<int,int>> table;//前面是數字 後面是總數量
        vector<int> path; //current path
        sort(can.begin(), can.end());

        // 2. 優化 table 的建構方式，消除 INT_MIN 與 insert 操作的記憶體開銷
        vector<pair<int,int>> table;
        for(int num : can){
            // 如果 table 是空的，或者遇到新的數字，就推入新的 pair
            if(table.empty() || table.back().first != num){
                table.push_back({num, 1});
            } 
            // 如果數字和上一個相同，直接將最後一個 pair 的數量 +1
            else {
                table.back().second++;
            }
        }

        backtrack(table,target,0,0,0,path,result);
        return result;
    }
};