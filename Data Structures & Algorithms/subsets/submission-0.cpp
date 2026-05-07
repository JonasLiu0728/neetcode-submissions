class Solution {
public:
    void traversal(vector<int>& nums, vector<vector<int>>& result,vector<int>& temp, int last,int shift){ // nums是reference result是結果 temp是要插入的 last是temp最後一個數字
        temp.push_back(nums[last+shift]);
        result.push_back(temp);
        last = last+shift; //更新最後一個數
        for( int i=1 ; i<=nums.size()-last-1 ; i++ ){//shift位置 從 last+1~最後一個
            traversal(nums,result,temp,last,i);
        }
        temp.pop_back(); //還原成原本的狀態
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            traversal(nums,result,temp,i,0);
        }
        return result;
    }
};
