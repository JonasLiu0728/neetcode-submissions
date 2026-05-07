class Solution {
public:
    int search(vector<int>& nums,int target,int low,int high){
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if( nums[mid]<target ) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for(int i=nums.size()-1;i>=0;i--){
            int temp = search( nums , target-nums[i] ,0,i-1);
            if(temp != -1){
                result.push_back(temp+1);
                result.push_back(i+1);
                break;
            }
        }
        //if(result[0] == result[1]) result[1]++;
        return result;
    }
};