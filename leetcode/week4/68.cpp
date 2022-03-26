class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        for(int i=0;i<words.size();){
            int len=words[i].size();
            int j=i+1;
            //j�ǵ�ǰ�����һ�����ʵ���һ������ +1����Ϊ��������֮������һ���ո�
            while(j<words.size()&&len+words[j].size()+1<=maxWidth)
                len+=(words[j++].size()+1);

            string line;
            line+=words[i];
            if(j==words.size()||j==i+1){//���������
                for(int k=i+1;k<j;k++) line+=(' '+words[k]);
                line+=string(maxWidth-len,' ');
            }else{//���Ҷ�������
                //cnt�Ǽ���� blank�ǿո��� +cnt����Ϊ10�м���1
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
