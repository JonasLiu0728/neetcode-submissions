class Solution {
public:
    void output(vector< vector<int> >& table){
        for(int i=0;i<table[0].size();i++){
            for(int j=0;j<table[0].size();j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<double> table(nums.size(), 0);
        vector<double> big(nums.size(), 0);
        vector<double> small(nums.size(), 0);
        
        double result = nums[0];
        table[0] = big[0] = small[0] = nums[0];
        
        // 取代原本的雙層迴圈 (d 和 i)，現在我們只需要順著陣列掃描一次
        for(int i = 1; i < nums.size(); i++){
            // 保留您的寫法：只不過 [i][i+d-1] 變成了前一個位置 [i-1]
            // nums[i+d] 變成了當前位置 nums[i]
            
            // 調整主陣列
            table[i] = max({ (double)nums[i], big[i-1] * nums[i], small[i-1] * nums[i] });
            // 調整big陣列
            big[i] = max({ (double)nums[i], big[i-1] * nums[i], small[i-1] * nums[i] });
            // 調整small陣列
            small[i] = min({ (double)nums[i], big[i-1] * nums[i], small[i-1] * nums[i] });
            
            // 寫答案
            if( table[i] > result) result = table[i];
        }
        
        return (int)result;
    }
};