class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high ){
            int mid = (low+high)/2;
            if(low == high){ //最右邊的或右邊比較小
                return nums[mid];
            }
            else if(high - low == 1){ //兩個元素的
                return (nums[low] < nums[high]) ? nums[low] : nums[high];
            }
            else if(nums[mid-1]>nums[mid]){ //真的找到
                return nums[mid];
            }
            else if( nums[mid] >= nums[low] && nums[low] >= nums[high] ){ //中 大 小
                low = mid+1;
            }
            else if( ( nums[high] >= nums[mid] && nums[mid] >= nums[low] )|| ( nums[low] >= nums[high] && nums[high] >= nums[mid] ) ){
                high = mid-1;
            }
            else{
                cout<<"出現錯誤"<<endl;
            }

        }
        return -6000;
    }
};