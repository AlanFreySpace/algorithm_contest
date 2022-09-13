package test;

public class Test1 {
	int a;
    int b;

    public void change(Test1[] t,int i) {
    	t[i].a=i;
    	t[i].b=i+1;
    }
    
    public static void main(String[] args)  {
        Test1[] test1=new Test1[5];
        for(int i=0;i<test1.length;i++) {
        	test1[i]=new Test1();
        	System.out.println(test1[i].a+" "+test1[i].b);
        }
        for(int i=0;i<test1.length;i++) {
        	test1[i].change(test1, i);
        	System.out.println(test1[i].a+" "+test1[i].b);
        }
    }
}
