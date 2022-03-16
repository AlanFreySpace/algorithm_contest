class Solution {
public:
    bool isValid(string s) {//利用栈解决即可
        stack<char> stk;
        for(auto c:s){
            if(c=='('||c=='{'||c=='[') stk.push(c);
            else{
                if(!stk.empty()){
                    if(c=='}'&&stk.top()!='{') return false;
                    else if(c==')'&&stk.top()!='(') return false;
                    else if(c==']'&&stk.top()!='[') return false;
                    stk.pop();
                }
                else return false;
            }
        }
        return stk.empty();
    }
};
