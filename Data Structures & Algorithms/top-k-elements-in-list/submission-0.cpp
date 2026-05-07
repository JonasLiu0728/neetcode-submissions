class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector< pair<int,int> > table;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int temp = 1;
            if(i == nums.size()-1){
                table.push_back({temp,nums[i]});
                break;
            }
            while(i!=nums.size()-1 && nums[i] == nums[i+1]){
                temp++;
                i++;
            }
            table.push_back({temp,nums[i]});
        }
        sort(table.begin(),table.end());
        for(int i=table.size()-k;i<table.size();i++){
            result.push_back( table[i].second );
        }
        return result;
    }
};