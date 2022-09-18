package test;
	
public class Test1 {
	public static void main(String[] args){
		Test1 o = new Test1();
        System.out.println(o.test());
    }
	
	private int test(){
        System.out.println("test1");
        return 1;
    }
}
