package test;
	
public class Test1 {
	int i;
	static int k;

	Test1(int i){
		int tmp=i;
		System.out.println(tmp);
		this.i = i;
		k=k+1;//写成this.k=this.k+1也行，输出完全相同
	}
	
	int j=i+1;
	
	public static void main(String[] args){
		Test1 t = new Test1(10);
		/*
		 * 写System.out.println(i);会报错不能使用
		 * 静态方式引用非静态的i
		 * 写System.out.println(k);是完全没问题的，
		 * 输出也相同
		 */
		System.out.println(t.i);
		System.out.println(t.j);
		System.out.println(k);
		Test1 t1 = new Test1(10);
		System.out.println(k);
    }
}
