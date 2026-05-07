void output(const unordered_map<string, vector<pair<int, string>>>& data) {
    // 第一層：遍歷 Map，將每個元素拆解為 key 與 history (即那個 vector)
    for (const auto& [key, history] : data) {
        cout << "Key: " << key << endl;

        // 第二層：遍歷該 Key 對應的 Vector
        for (const auto& [timestamp, val] : history) {
            cout << "  [Time: " << timestamp << ", Value: " << val << "]" << endl;
        }
        cout << "-----------------------" << endl;
    }
}

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
        //output(data);
    }
    

    string get(string key, int timestamp) {
        auto it = data.find(key);
        if (it == data.end()) return "";
        int low = 0; //會停在第一個「大於」目標值的位置。
        int high = it->second.size()-1; //high 停在最後一個「小於或等於」目標值的位置。
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if( it->second[mid].first > timestamp ){ //high會先移動
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if( high==-1 ) return "";
        return  it->second[high].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */