class Solution {
public:
    string getPermutation(int n, int k) {//方法一:计数法 时间复杂度O(n^2)
        string ans;
        vector<int> fact(10);
        vector<bool> use(10);
        fact[0]=1;
        for(int i=1;i<10;i++) fact[i]=fact[i-1]*i;//fact[i]=i!

        //在数字的第i个位置(位置从1开始)尝试放数字j
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!use[j]){
                    if(fact[n-i]<k) k-=fact[n-i];
                    else{
                        ans+=('0'+j);
                        use[j]=true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

/*
方法二:使用next_permutation函数 存疑:时间复杂度O(n!*k)
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for(int i=1;i<=n;i++) ans+=('0'+i);
        for(int i=0;i<k-1;i++)
            next_permutation(ans.begin(),ans.end());
        return ans;
    }
};
