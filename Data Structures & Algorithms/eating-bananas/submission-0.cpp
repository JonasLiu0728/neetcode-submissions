class Solution {
public:
    bool can_finish(const vector<int>& piles,int h,int speed){
        for(int i=0;i<piles.size();i++){
            h -= (piles[i]+speed-1)/speed;
            if( h<0 ) return 0;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<piles.size();i++){
            if( piles[i]>high ) high = piles[i];
        }
        
        int result = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if( can_finish(piles,h,mid) ){ //可以吃完 找更小的speed
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};