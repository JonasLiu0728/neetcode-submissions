class Solution {
public:
    void output(vector<int>& exist){
        for(int i=0;i<exist.size();i++){
            cout<<exist[i]<<" ";
        }
        cout<<endl;
    }
    vector<int> partitionLabels(string s) {
        vector<int> result;
        //vector<int> first_exist(26,-1);
        vector<int> last_exist(26,0);
        for(int i=0;i<s.size();i++){
            //if(first_exist[s[i]-97]==-1) first_exist[s[i]-97] = i;
            last_exist[s[i]-97] = i;
        }
        //output(first_exist);
        //output(last_exist);
        for(int i=0;i<s.size();i++){
            int split = last_exist[s[i]-97]; // interval of first alphabet
            for(int j=i+1;j<split;j++){ //檢查這個 split 裡面所有的
                if( last_exist[ s[j]-97 ] > split ) split = last_exist[ s[j]-97 ];
            }
            result.push_back(split+1);
            i = split; //不用+1 for迴圈會自動幫我+1
        }
        //cout<<"切點:";
        //output(result);
        for(int i=result.size()-1;i>0;i--){
            result[i] = result[i]-result[i-1];
        }
        return result;
    }
};