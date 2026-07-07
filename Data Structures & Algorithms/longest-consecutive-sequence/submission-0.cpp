class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        int max = INT_MIN;
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        if(set.empty()) return 0;
        /*
        while(!set.empty()){
            int center = *set.begin(); //set.begin是一個pointer 所以要取值
            int temp = center;
            int temp_length = 1;
            //往左邊找
            while( set.count( temp-1 ) ){
                temp_length++;
                set.erase(temp-1);
                temp--;
            }
            temp = center;
            while( set.count( temp+1 ) ){
                temp_length++;
                set.erase(temp+1);
                temp++;
            }
            if(temp_length > max) max = temp_length;
            set.erase(center);
        }
        */
        for(int num : set){
            //判斷是不是開頭
            int temp = num; //set.begin是一個pointer 所以要取值
            int temp_length = 1;
            if( set.count( temp-1 ) ){
                continue;
            }
            while( set.count( temp+1 ) ){
                temp_length++;
                temp++;
            }
            if(temp_length > max) max = temp_length;
        }

        return max;
    }
};