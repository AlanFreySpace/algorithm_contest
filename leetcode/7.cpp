class Solution {
public:
    /*
    注意在C++中-4%10=-4
    */
    int reverse(int x) {//秦九韶算法
        int r=0;
        /*
        记忆方法:由r*10+x%10>INT_MAX移项即可
        但是考虑到下取整等问题 实际推导步骤更为复杂(移项写一下可看出来)
        */
        while(x){
            if(x>0&&r>(INT_MAX-x%10)/10) return 0;//判断是否溢出
            if(x<0&&r<(INT_MIN-x%10)/10) return 0;
            r=r*10+x%10;
            x/=10;
        }
        return r;
    }
};
