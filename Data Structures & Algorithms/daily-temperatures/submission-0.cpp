class Solution {
public:
/*
    void output(stack<int> stack){
        cout<<"====================="<<endl;
        while(!stack.empty()){
            cout<<stack.top()<<endl;
            stack.pop();
        }
        cout<<"====================="<<endl;
    }
*/
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> stack; //stack存的是index
        vector<int> result( t.size(),0 );
        for(int i=0;i<t.size();i++){
            while( !stack.empty() && t[i] > t[stack.top()] ){ //解決前面還沒解決的
                result[ stack.top() ] = i - stack.top();
                //cout<<"解決:"<<stack.top()<<endl;
                stack.pop();
                //output(stack);
            }
            stack.push( i );
            //output(stack);
        }
        return result;
    }
};