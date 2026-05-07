class Solution {
public:
    void traversal(vector<int>& nums, vector<vector<int>>& result,vector<int>& temp, int last,int shift){ // nums是reference result是結果 temp是要插入的 last是temp最後一個數字
        temp.push_back(nums[last+shift]);
        result.push_back(temp);
        last = last+shift; //更新最後一個數
        for( int i=1 ; i<=nums.size()-last-1 ; i++ ){//shift位置 從 last+1~最後一個
            if(i!=1 && nums[last+i]==nums[last+i-1]) continue;
            traversal(nums,result,temp,last,i);
        }
        temp.pop_back(); //還原成原本的狀態
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        result.reserve(1<<nums.size()); //預先保留2^(size)次方的空間給result
        result.push_back({});
        vector<int> temp;
        temp.reserve(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue; //pruning
            traversal(nums,result,temp,i,0);
        }
        return result;
    }
};