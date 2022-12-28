package week4;

public class p65 {
	public boolean isNumber(String s) {
        int index=0,res=0;
        if(s.charAt(index)=='+'||s.charAt(index)=='-') index++;
        if(index>=s.length()) return false;
        if(index<s.length()){
            res=isInteger(s,index);
            index+=res;
        }
        if(index<s.length()){
            if(res==0&&s.charAt(index)!='.') return false;
            if(res==0&&s.charAt(index)=='.'){
                index++;
                res=isInteger(s,index);
                if(res==0) return false;
                else index+=res;
            }else{
                if(s.charAt(index)=='.'){
                    index++;
                    if(index<s.length()){
                        res=isInteger(s,index);
                        index+=res;
                    }
                    
                }
                else if(s.charAt(index)=='e'||s.charAt(index)=='E') index++;
                else return false;
            }
        }
        
        return true;
    }

    int isInteger(String s,int index){
        int len=0;
        for(int i=index;i<s.length();i++){
            char tmp=s.charAt(i);
            if(tmp>='0'&&tmp<='9') len++;
            else break;
        }
        return len;
    }
}
