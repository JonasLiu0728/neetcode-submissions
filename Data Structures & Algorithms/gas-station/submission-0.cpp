class Solution {
public:
    int insuccess(vector<int>& diff,int start){
        int n = diff.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= diff[(start+i)%n];
            if(sum<0) return (start+i)%n;
        }
        return -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n,0);
        int total_diff = 0;
        for(int i=0;i<n;i++){
            diff[i] = gas[i]-cost[i];
            total_diff+=diff[i];
        }
        if( total_diff<0 ) return -1;
        for(int i=0;i<n;i++){
            int temp = insuccess(diff,i);
            if(temp==-1) return i;
            else i=temp;
        }
        return -1;
    }
};