package test;

public class test1 {
	int x;
    static class Inner{
        static int a = 0;//这样写是不合法的
        static final int b=0;//这样写是合法的
        int c=0;
    }

	
	
    public static void main(String[] args)  {
        
    }
}