class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int max = 0;

        while(left<right){
            int curr_max = (right-left)*min(height[left],height[right]);
            if( curr_max > max ) max = curr_max;

            if( height[left] <= height[right] ){
                left++;
            }
            else if( height[left] > height[right] ){
                right--;
            }
        }
        return max;
    }
};