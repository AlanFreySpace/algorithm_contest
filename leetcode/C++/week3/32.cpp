class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        stack<int> stk;

        //start 表示上一段第一次出现不合法的括号序列的右括号的位置
        for(int i=0,start=-1;i<s.size();i++){
            //如果是左括号，左括号下标入栈
            if(s[i]=='(') stk.push(i);
            else{//右括号
                if(stk.size()){//栈不为空，将当前右括号匹配掉
                    stk.pop();//弹出与之匹配的左括号
                    /*
                    如果当前栈中还有左括号，说明从栈顶所在位置的下一个位置到这个右括号之间
                    是一个合法的括号序列，所以更新长度（样例："(()()"）
                    否则如果和当前右括号匹配结束后，当前栈为空，那么从 start 位置开始的下一个
                    位置（即下一段的开始位置）到当前右括号之间是一个合法的括号序列，所以用start
                    更新长度（样例："()()"）
                    */
                    if(stk.size()){
                        res=max(res,i-stk.top());
                    }else{
                        res=max(res,i-start);
                    }
                }else{//如果当前右括号不能匹配成功，那这个位置就是这一段第一次出现不合法的括号序列的位置，更新start
                    start=i;
                }
            }
        }
        return res;
    }
};
