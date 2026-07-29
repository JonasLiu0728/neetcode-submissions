class Solution {
public:
    void output(vector<vector<int>>& table){
        for(int i=0;i<table.size();i++){
            for(int j = 0;j<table.size();j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> table(n,vector<int>(n,0));
        for(int i=2;i<n;i++){
            for(int j=0;j+i<=n-1;j++){ // Control interval
                int MAX = INT_MIN;
                for( int k=j+1 ; k<=j+i-1 ; k++){ // K is the last to remove
                    //cout<<"j/i/k:"<<j<<" "<<i<<" "<<k<<endl;
                    //cout<<"Two Subproblem:"<<"["<<j<<","<<k<<"]"<<" / "<<"["<<k<<","<<j+i<<"]"<<endl;
                    //cout<<"INFO:"<<table[j][k]<<" / "<<nums[j]*nums[k]*nums[j+i]<<" / "<<table[k][j+1]<<"\n\n";
                    int curr = table[j][k] + nums[j]*nums[k]*nums[j+i] + table[k][j+i];
                    if(curr>MAX) MAX = curr;
                }
                table[j][j+i] = MAX;
                //output(table);
            }
        }
        return table[0][n-1];
    }
};