class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1; 

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            //判斷哪邊擠爆了
            if (count > mid) {
                high = mid; 
            } else {
                low = mid + 1;
            }
        }

        // 當 low == high 時，即為找到的重複數字
        return low;
    }
};