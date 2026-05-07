

//arrange成功 return 0 否則 return minimum interval



class Solution {
public:
    void output_stat(vector<pair<int,char>>& table){
        cout<<"====================================="<<endl;
        for(int i=0;i<table.size();i++){
            cout<<table[i].first<<" "<<table[i].second<<" "<<endl;
        }
        cout<<"====================================="<<endl;
    }
    bool is_greater(pair<int,char>& A , pair<int,char>& B){
        if (  A.first  > B.first )  return 1;
        else return 0;
        return 0;
    }
    
    void push_heap(vector<pair<int,char>>& temp,pair<int,char>& A){
        temp.push_back(A);
        to_heap(temp);
    }
    pair<int,char> pop_heap(vector<pair<int,char>>& temp){
        pair<int,char> max_val = temp[0];
        temp[0] = temp[temp.size()-1];
        temp.pop_back();
        if(!temp.empty()){
            heapify(temp,temp.size(),0);
        }
        return max_val;
    }
    void heapify(vector<pair<int,char>>& temp, int n, int index){
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
    
    void to_heap(vector<pair<int,char>>& temp){
        int n = temp.size();
        for(int i= (n/2-1) ; i>=0 ; i-- ){
            heapify(temp,n,i);
        }
    }

    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<int,char>> table;// store the used label
        int task_size = tasks.size();
        tasks.insert(tasks.begin(),'@');
        sort(tasks.begin(),tasks.end());
        
        for(int i=1;i<tasks.size();i++){
            if(tasks[i-1]!=tasks[i]){
                char temp = tasks[i];
                table.push_back( {1,tasks[i]} );
                while( i+1<tasks.size() && tasks[i+1]==temp ){
                    //cout<<i<<":"<<"看到"<<tasks[i]<<endl;
                    table[table.size()-1].first++;
                    i++;
                }  
            } 
        }

        to_heap(table);
        // heap建立完成
        
        // Create a queue for cooling schedule
        queue< pair<pair<int,char>,int> > Q;

        int time = 0;
        while(!Q.empty()||!table.empty()){
            //時間+1
            time++;
            //把冷卻狀態中的救出來
            if(!Q.empty() && Q.front().second == time){
                push_heap( table , Q.front().first );
                Q.pop();
            }
            //執行一份工作
            //把做完的丟到冷卻狀態
            if(!table.empty()){
                pair<int,char> temp = pop_heap(table);
                temp.first--;
                if(temp.first>0){//還沒做完 push 進 queue冷卻
                    Q.push({temp,time+n+1});
                }
            }
        }

        return time;
    }
};