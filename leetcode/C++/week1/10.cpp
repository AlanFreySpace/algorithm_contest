class Solution {//利用动态规划求解 时间复杂度O(n^2)
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        s=' '+s,p=' '+p;
        vector<vector<bool>> f(n+1,vector<bool>(m+1));
        f[0][0]=true;
		/*
		这里的实现还是很细节的,主要有两方面:
		1.令s1=' '+s,p1=' '+p,则s1和p1匹配是s和p匹配的充要条件
		2.基于1,仔细考虑边界情况:即考虑s1[0]和p1[0~s.length()]的匹配情况:
		  i.若i为0且p[j]!='*',此时s1[0]和p1[0,j]不可能匹配,因此用if(i&&p[j]!='*')将
		  这一情况划掉
		  ii.若i为0且p[j]=='*',此时s1[0]和p1[0,j]有可能匹配,例如p1[0,j]=' .*.*.*',
		  p1[0,j]=' 1*2*.*'等,因此这种情况不能被排除不判断,因此用了if(p[j]=='*')这一
		  条件
		*/
		/*
		注意i&&f[i-1][j]中i是要防止i越界
		*/
		//continue作用是让程序忽略循环中剩余的语句,立刻跳转到下一次循环的迭代
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j+1<=m&&p[j+1]=='*') continue;//应归入*匹配的情况
                if(i&&p[j]!='*')//注意运算符优先级 用(s[i]==p[j]||p[j]=='.')表示
                    f[i][j]=(s[i]==p[j]||p[j]=='.')&&f[i-1][j-1];
                if(p[j]=='*')
                    f[i][j]=f[i][j-2]||(i&&f[i-1][j])&&(s[i]==p[j-1]||p[j-1]=='.');
            }
        }
        return f[n][m];
    }
};
