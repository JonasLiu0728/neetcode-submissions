class Solution {
public:
    void output(vector<vector<int>>& tri){
        for(int i=0;i<tri.size();i++){
            for(int j=0;j<tri[0].size();j++){
                cout<<tri[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    bool possible(vector<int>& curr,vector<int>& target,vector<bool>& track){
        if( curr[0]!=target[0] && curr[1]!=target[1] && curr[2]!=target[2] ) return false;
        if( curr[0]>target[0] || curr[1]>target[1] || curr[2]>target[2] ) return false;

        for(int i=0;i<track.size();i++){
            if(curr[i]==target[i]) track[i] = true;
        }
        return true;
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> track(3,false);
        for(int i=0;i<triplets.size();i++){
            possible(triplets[i],target,track);
        }
        
        return track[0]&&track[1]&&track[2];
    }
};