class Solution {
public:
    void output(vector< vector<int> >& table){
        for(int i = 0; i < table.size(); i++){
            for(int j = 0; j < table[i].size(); j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target = 0;
        for(int i=0;i<nums.size();i++){
            target += nums[i];
        }
        if(target%2!=0||nums.size()==1) return false;
        target = target/2;
        vector<int> A(target+1, 0);
        vector<int> B(target+1, 0);

        vector<int>* prev = &A;
        vector<int>* curr = &B;

        A[nums[0]] = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<target+1;j++){
                
                if( (*prev)[j] == 1 ){
                    (*curr)[ j ] = 1;
                    continue;
                } 
                if( j-nums[i]>=0 && (*prev)[ j-nums[i] ] == 1 ){//
                    (*curr)[ j ] = 1;
                }
                
            }
            vector<int>* temp = prev;
            prev = curr;
            curr = temp;
        }
        return (*prev)[target];
    }
};