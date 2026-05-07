class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot;
        int low = 0;
        int high = nums.size()-1;
        while(low <= high ){
            int mid = (low+high)/2;
            if(low == high){ //最右邊的或右邊比較小
                pivot = mid;
                break;
            }
            else if(high - low == 1){ //兩個元素的
                if(nums[low] < nums[high]){
                    pivot = low;
                    break;
                }
                else{
                    pivot = high;
                    break;
                }
            }
            else if(nums[mid-1]>nums[mid]){ //真的找到
                pivot = mid;
                break;
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
        
        //binary search
        low = 0;
        high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2; 
            int real_mid = (mid+pivot)%nums.size();

            if(nums[real_mid] == target) return real_mid;
            else if( nums[real_mid] > target ){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};