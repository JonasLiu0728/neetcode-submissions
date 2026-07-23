class Solution {
public:
    void info(string s,int back,int front,int current,int max){
        cout<<"======================"<<endl;
        cout<<"back:"<<s[back]<<" front:"<<s[front]<<endl;
        cout<<"back:"<<back<<endl;
        cout<<"front:"<<front<<endl;
        cout<<"當前長度:"<<current<<endl;
        cout<<"最大長度:"<<max<<endl;
        cout<<"======================"<<endl<<endl;
    }
    int lengthOfLongestSubstring(string s) {
        //cout<<"["<<s<<"]"<<endl;
        int front=0,back=0,current=0,max=0;
        unordered_set<char> dic;
        if( !s.size() ) return 0;
        while(front!=s.size()){
            //cout<<"============================================="<<endl;
            //cout<<"-----------------此輪開始---------------------"<<endl;
            //info(s,back,front,current,max);

            current++;
            if( dic.count(s[front])==0 ){ //不存在
                dic.insert(s[front]);
            }
            else{
                while( dic.count(s[front])==1 ){
                    dic.erase(s[back]);
                    back++;
                    current--;
                }
                //刪除完再加入
                dic.insert(s[front]);
            }
            if(current>max) max = current;
            front++;
            //cout<<"-----------------此輪結束---------------------"<<endl;
            //info(s,back,front,current,max);
            //cout<<"============================================="<<endl;
        }
        return max;
    }
};