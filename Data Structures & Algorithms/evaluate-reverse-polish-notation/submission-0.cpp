class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> value;
        for(int i=0;i<tokens.size();i++){
            if( tokens[i] == "+"){
                int a,b;
                a = value.top();
                value.pop();
                b = value.top();
                value.pop();
                value.push( b+a );
                //output(value);
            }
            else if( tokens[i] == "-"){
                int a,b;
                a = value.top();
                value.pop();
                b = value.top();
                value.pop();
                value.push( b-a );
                //output(value);
            }
            else if( tokens[i] == "*"){
                int a,b;
                a = value.top();
                value.pop();
                b = value.top();
                value.pop();
                value.push( b*a );
                //output(value);
            }
            else if( tokens[i] == "/"){
                int a,b;
                a = value.top();
                value.pop();
                b = value.top();
                value.pop();
                value.push( b/a );
                //output(value);
            }
            else{
                value.push( stoi(tokens[i]) );
                //output(value);
            }
        }
        return value.top();        
    }
};