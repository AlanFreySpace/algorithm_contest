package week4;

import java.util.ArrayList;
import java.util.List;

public class p68 {
	public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans=new ArrayList<>();

        for(int i=0;i<words.length;){
            int size=words[i].length();
            int j=i+1;
            while(j<words.length&&size+words[j].length()+1<=maxWidth)
                size+=(words[j++].length()+1);

            System.out.println(size);

            String line="";
            if(j==words.length||j==i+1){
                line=words[i];
                int len=maxWidth-words[i].length();
                for(int k=0;k<len;k++) line+=" ";
            }else{
                int cnt=j-i-1,blank=maxWidth-size+cnt;
                int k=0;
                for(;k<blank%cnt;k++){
                    line+=words[i+k];
                    for(int u=0;u<=blank/cnt;u++) line+=" ";
                }
                for(;k<cnt;k++){
                    line+=words[i+k];
                    for(int u=0;u<blank/cnt;u++) line+=" ";
                }
                line+=words[i+cnt];
            }

            ans.add(line);
            i=j;
        }

        return ans;
    }
}
