class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        for(int i=0;i<words.size();){
            int len=words[i].size();
            int j=i+1;
            //j是当前行最后一个单词的下一个单词 +1是因为两个单词之间至少一个空格
            while(j<words.size()&&len+words[j].size()+1<=maxWidth)
                len+=(words[j++].size()+1);

            string line;
            line+=words[i];
            if(j==words.size()||j==i+1){//左对齐的情况
                for(int k=i+1;k<j;k++) line+=(' '+words[k]);
                line+=string(maxWidth-len,' ');
            }else{//左右对齐的情况
                //cnt是间隔数 blank是空格数 +cnt是因为10行加了1
                int cnt=j-i-1,blank=maxWidth-len+cnt;
                int k=1;
                while(k<=blank%cnt) line+=(string(blank/cnt+1,' ')+words[i+k++]);
                while(k<=cnt) line+=(string(blank/cnt,' ')+words[i+k++]);
            }
            res.push_back(line);
            i=j;
        }

        return res;
    }
};
