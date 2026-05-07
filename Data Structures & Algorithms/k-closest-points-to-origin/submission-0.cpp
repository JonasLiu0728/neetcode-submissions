class Solution {
public:
    bool is_greater(vector<int>& A , vector<int>& B){
        if ( ( A[0]*A[0]+A[1]*A[1] ) > ( B[0]*B[0]+B[1]*B[1] ) ) return 1;
        else return 0;
        return 0;
    }
    void heapify(vector<vector<int>>& temp, int n, int index){
        int largest = index;
        int left = index*2+1;
        int right = index*2+2;
        
        // left放小的
        if (left < n && is_greater(temp[left], temp[largest])) {
            largest = left;
        }
        if (right < n && is_greater(temp[right], temp[largest])) {
            largest = right;
        }
        if( largest!=index  ){ //左邊比較大 左邊換上去
            swap( temp[index], temp[largest] );
            heapify(temp,n,largest);
        }        
    }
    
    void to_heap(vector<vector<int>>& temp){
        int n = temp.size();
        for(int i= (n/2-1) ; i>=0 ; i-- ){
            heapify(temp,n,i);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int count=0;
        vector<vector<int>> heap; //是一個max heap
        for(int i=0;i<k;i++){
            heap.push_back(points[i]);
        }
        to_heap(heap);
        for(int i=k;i<points.size();i++){
            if( is_greater(heap[0],points[i]) ){
                heap[0] = points[i];
                heapify(heap,k,0);
            }
        }
        return heap;
    }
};