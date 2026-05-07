class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(1,1);
        vector<int> right_product(1,1);
        int left_temp=1;
        int right_temp=1;
        for(int i=0;i<nums.size()-1;i++){
            left_temp*=nums[i];
            right_temp*=nums[nums.size()-1-i];
            left_product.push_back(left_temp);
            right_product.push_back(right_temp);
        }
        vector<int> result(nums.size());
        for(int i=0;i<result.size();i++){
            result[i] = left_product[i]*right_product[nums.size()-1-i];
        }
        return result;
    }
};