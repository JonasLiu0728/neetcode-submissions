class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reach = 0;
        int max_index = 0;
        int step = 0;
        while(max_reach<nums.size()-1){
            int new_max_index = max_index;
            int new_max_reach = max_reach;
            for(int i=0;i<=max_reach;i++){
                if( i+nums[i]>new_max_reach ){
                    new_max_reach = i+nums[i];
                    new_max_index = i;
                }   
            }
            max_reach = new_max_reach;
            max_index = new_max_index;
            step++;
        }
        return step;
    }
};