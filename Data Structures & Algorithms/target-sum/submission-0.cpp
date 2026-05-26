class Solution {
public:
    void output(vector< vector<long long> >& table){
        for(int i = 0; i < table.size(); i++){
            for(int j = 0; j < table[i].size(); j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        if(sum<abs(target)) return 0;
        int range = sum*2;
        vector<vector<long long>> table(nums.size(),vector<long long>(sum*2+1,0));
        // 初始化第一排
        table[0][sum+nums[0]] += 1;
        table[0][sum-nums[0]] += 1;
        for(int i=1;i<nums.size();i++){
            //output(table);
            for(int j=0;j<nums[i];j++){ //只加右邊
                table[i][j] = table[i-1][j+nums[i]];
            }
            for(int j=nums[i];j<=range-nums[i];j++){
                table[i][j] = table[i-1][j+nums[i]] + table[i-1][j-nums[i]];
            }
            for(int j=range-nums[i]+1;j<=range;j++){
                table[i][j] = table[i-1][j-nums[i]];
            }
        }
        return table[nums.size()-1][sum+target];
    }
};