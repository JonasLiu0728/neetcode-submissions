class Solution {
public:
    void output_heap(vector<int>& temp){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(vector<int>& temp,int index){
        int smallest = index;
        int left = index*2 + 1;
        int right = index*2 + 2;

        if( left<temp.size() && temp[smallest] > temp[left] ){
            smallest = left;
        }
        if( right<temp.size() && temp[smallest] > temp[right] ){
            smallest = right;
        }
        if(smallest!=index){
            swap(temp[smallest],temp[index]);
            heapify(temp,smallest);
        }
    }
    void to_heap(vector<int>& temp){
        int n = temp.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapify(temp,i);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> min_heap;
        for(int i=0;i<k;i++){
            min_heap.push_back(nums[i]);
        }
        to_heap(min_heap);
        for(int i=k;i<nums.size();i++){
            //output_heap(min_heap);
            if( nums[i] > min_heap[0] ){
                min_heap[0] = nums[i];
                heapify(min_heap,0);
            }
        }
        //output_heap(min_heap);
        return min_heap[0];
    }
};


