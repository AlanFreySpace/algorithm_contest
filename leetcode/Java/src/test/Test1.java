package test;

public class Test1 {
	void ab(){
		final int aa;
		aa++;
		System.out.println(aa);
	} 
	
	public static void main(String[] args) {
		Test1 test1=new Test1();
		test1.ab();
	}
}
