class Solution {
public:
    int local_search( vector<int>& matrix, int target ){
        int low = 0;
        int high = matrix.size()-1;

        while( low<=high ){
            int mid = (low+high)/2;
            if( matrix[mid] == target ) return true;
            else if(matrix[mid] < target){
                low = mid+1;
            }
            else if(matrix[mid] > target){
                high = mid-1;
            }
        }
        return false;
    }
    int global_search(vector<vector<int>>& matrix, int target){
        int low = 0;
        int high = matrix.size()-1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int global = global_search(matrix,target);
        if( global!=-1 ){
            if( local_search( matrix[global],target ) ) return true;
            else return false;
        }
        return false;
    }
};