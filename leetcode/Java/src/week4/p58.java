package week4;

public class p58 {
	//注意这种双指针的方法
	public int lengthOfLastWord(String s) {
        int len=s.length(),i=0,j=0;
        for(i=len-1;i>=0;i--){
            if(s.charAt(i)!=' '){
                j=i-1;
                while(j>=0&&s.charAt(j)!=' ') j--;
                break;
            }
        }
        return i-j;
    }
}
