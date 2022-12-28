package week4;

public class p65 {
	int i=0;
    public boolean isNumber(String s) {
        boolean numerical=isInteger(s);
        if(i<s.length()&&s.charAt(i)=='.'){
            i++;
            numerical=isUnsignedInteger(s)||numerical;
        }
        if(i<s.length()&&(s.charAt(i)=='e'||s.charAt(i)=='E')){
            i++;
            numerical=numerical&&isInteger(s);
        }
        return numerical&&(i==s.length());
    }

    boolean isInteger(String s){
        if(i<s.length()&&(s.charAt(i)=='+'||s.charAt(i)=='-')) i++;
        return isUnsignedInteger(s);
    }

    boolean isUnsignedInteger(String s){
        int p=i;
        while(i<s.length()&&s.charAt(i)>='0'&&s.charAt(i)<='9') i++;
        return p<i;
    }
}
