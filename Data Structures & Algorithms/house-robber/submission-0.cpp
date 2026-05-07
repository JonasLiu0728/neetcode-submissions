class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> value(nums.size());
        value[0] = nums[0]; 
        value[1] = max(nums[0],nums[1]);
        int result = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            //cout<<value[i-2]+nums[i]<<" "<<value[i-1]<<endl;
            value[i] = max(value[i-2]+nums[i],value[i-1]); //不選前一個選自己 or 選前一個不選自己
            if(value[i]>result) result = value[i]; 
        }
        return result;
    }
};