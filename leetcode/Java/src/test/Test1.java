package test;
	
public class Test1 {
	public static void main(String[] args){
		Son1 s = new Son1();
    }
}

class Father1{
	public void Father1() {
		System.out.println("父类中的有参构造方法");
	}
}

class Son1 extends Father1{
	
}