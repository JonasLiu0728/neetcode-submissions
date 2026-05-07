
void output_heap(vector<int>& temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

class MinHeap{
public:
    vector<int> heap;
    void heapify(int index){
        int n = heap.size();
        int smallest = index;
        int left = index*2+1;
        int right = index*2+2;

        if( left<n && heap[left] < heap[smallest]){
            smallest = left;
        }
        if( right<n && heap[right] < heap[smallest]){
            smallest = right;
        }
        if(index!=smallest){
            swap(heap[index],heap[smallest]);
            heapify(smallest);
        }
    }
    void sift_up(int index){
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void push(int n){
        heap.push_back(n);
        sift_up(heap.size()-1);
    }

    int pop(){
        if(heap.size()==0){
            cout<<"Min Heap is empty"<<endl;
            return -1;
        }
        int result = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        if(!heap.empty()){
            heapify(0);
        }
        return result;
    }
};
class MaxHeap{
public:
    vector<int> heap;
    void heapify(int index){
        int n = heap.size();
        int largest = index;
        int left = index*2+1;
        int right = index*2+2;
        
        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }
        if( largest!=index  ){ //左邊比較大 左邊換上去
            swap( heap[index], heap[largest] );
            heapify(largest);
        }        
    }

    void sift_up(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    void push(int n){
        heap.push_back(n);
        sift_up(heap.size()-1);
    }
    int pop(){
        if(heap.size()==0){
            cout<<"Max Heap is empty"<<endl;
            return -1;
        }
        int result = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        if(!heap.empty()){
            heapify(0);
        }
        return result;
    }
};

class MedianFinder {
private:
    MinHeap min_heap;
    MaxHeap max_heap;
    bool balanced; //如果左邊heap大於右邊 則為 false
public:
    MedianFinder() {
        balanced = true;
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.pop());
        if (min_heap.heap.size() > max_heap.heap.size()) max_heap.push(min_heap.pop());
    }
    
    double findMedian() {
        if(max_heap.heap.size()-min_heap.heap.size()==0){ //兩邊平衡
            return double(max_heap.heap[0]+min_heap.heap[0])/2;
        }
        return max_heap.heap[0];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */