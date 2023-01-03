package week5;

public class p71 {
	public String simplifyPath(String path) {
        int len=path.length();
        if(path.charAt(len-1)!='/') path+='/';
        String tmp="";

        len=path.length();
        for(int i=1;i<len;i++){
            char c=path.charAt(i);
            if(c=='/'){

            }else tmp+=c;
        }

        return path;
    }
}
