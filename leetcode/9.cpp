//方法一
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        string s=to_string(x);
        return s==string(s.rbegin(),s.rend());//反转字符串 反向迭代器
    }
};

//方法二 数值方法
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        int y=x;
        long long res=0;
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        return y==res;
    }
};
