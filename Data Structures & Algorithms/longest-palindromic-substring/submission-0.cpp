class Solution {
public:
    int expand_odd(string s,int place){
        //cout<<"[Expand odd]"<<endl;
        int length=1;
        for(int i=1;i<=(s.size()/2);i++){
            //cout<<"i="<<i<<endl;
            if(place-i < 0 || place+i >= s.size()) break;
            if( s[place-i]==s[place+i] && place-i >=0 && place+i < s.size()){
                //cout<<place-i<<""<<s[place-i]<<"跟"<<place+i<<" "<<s[place+i]<<"一樣 ";
                length+=2;
            }
            else break;
        }
        //cout<<"length:"<<length<<endl;
        return length;
    }

    int expand_even(string s,int place){
        //cout<<"[Expand even]"<<endl;
        int length=0;
        
        for(int i=0;i<=(s.size()/2);i++){
            if(place-i < 0 || place+i+1 >= s.size()) break;
            if( s[place-i]==s[place+i+1] && place-i >=0 && place+i+1 < s.size()){
                //cout<<place-i<<""<<s[place-i]<<"跟"<<place+i+1<<" "<<s[place+i+1]<<"一樣 ";
                length+=2;
            }
            else break;
        }
        return length;
    }
    string longestPalindrome(string s) {
        int temp;
        int length=1;//回文的長度
        int pos=0;//回文的中心點
        
        for(int i=0;i<s.size();i++){
            temp = expand_odd(s,i);
            if(temp > length){
                length = temp;
                pos = i;
            }
            temp = expand_even(s,i);
            if(temp > length){
                length = temp;
                pos = i;
            }
        }
        string result = "";
        if(length%2==0){
            for(int i=pos-(length/2)+1 ; i<=pos+(length/2) ; i++ ){
                result+=s[i];
            }
        }
        else{
            for(int i=pos-(length/2) ; i<=pos+(length/2) ; i++ ){
                result+=s[i];
            }
        }
        
        return result;
    }
};

/*
[0] [1] [2] [3] [4] [5] [6] [7] [8]
"cbbd"
length/2
*/