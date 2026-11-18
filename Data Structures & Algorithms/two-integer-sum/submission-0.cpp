class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> table;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            table.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            if(table.contains(target-nums[i]) && table[target-nums[i]]!=i){//可以配對
                result.push_back( i );
                result.push_back( table[ target-nums[i] ] );
                sort(result.begin(),result.end());
                return result;
            }
        }
        return result;
    }
};