package test;

public class test1 {
	int x;
	static void c() {}
	
    public static void main(String[] args)  {
    	test1 t=new test1();
        System.out.println(t.x);
        test1.c();//使用类名调用静态方法
    }
}
