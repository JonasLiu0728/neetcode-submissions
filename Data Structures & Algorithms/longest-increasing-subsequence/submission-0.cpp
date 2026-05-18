class Solution {
public:
    void output(vector<int>& table){
        for(int i=0;i<table.size();i++){
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> table(nums.size(),0);
        table[0] = 1;
        int result = 1;
        for(int i=1;i<nums.size();i++){
            int curr_max = 1;
            table[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && table[j]+1>curr_max){ //可以接上去
                    table[i] = table[j]+1;
                    curr_max = table[j]+1;
                }
            }
            if(result<table[i]) result = table[i];
        }

        
        return result;
    }
};