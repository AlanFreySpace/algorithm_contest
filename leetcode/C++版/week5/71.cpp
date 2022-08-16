class Solution {
public:
    string simplifyPath(string path) {
        string ans,tmp;
        if(path.back()!='/') path+='/';

        for(auto c:path){
            if(c!='/') tmp+=c;
            else{
                if(tmp==".."){
                    while(ans.size()&&ans.back()!='/') ans.pop_back();
                    if(ans.size()) ans.pop_back();//删除多余的'/'
                }
                else if(tmp.size()&&tmp!="."){
                    ans+=('/'+tmp);
                }
                tmp.clear();
            }
        }

        if(ans.empty()) ans="/";
        return ans;
    }
};
