class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        cout<<endl;
        
        for(int i=0;i<=nums.size()-3;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int low = i+1;
            int high = nums.size()-1;
            while( low<high ){
                if(target == nums[low]+nums[high]){
                    result.push_back( {nums[i],nums[low],nums[high]} );
                    while( low<high && nums[low] == nums[low+1] ) low++;
                    while( low<high && nums[high] == nums[high-1] ) high--;
                    low++;
                    high--;               
                }
                else if( target < nums[low]+nums[high] ){
                    high--;
                } 
                else if( target > nums[low]+nums[high] ){
                    low++;
                } 
            }
        }
        return result;
    }
};