class Solution {
public:
    void generate_permutation(vector<int>& nums,int start,vector<vector<int>>& result){
        if(start==nums.size()) result.push_back(nums);
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            generate_permutation(nums,start+1,result);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate_permutation(nums,0,result);
        return result;
    }
};