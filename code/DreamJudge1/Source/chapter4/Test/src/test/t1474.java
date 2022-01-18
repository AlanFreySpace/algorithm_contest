package test;
import java.math.BigInteger;
import java.util.Scanner;
//评测时类名应为Main
public class t1474 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()) {
			BigInteger a,b;
			a=sc.nextBigInteger();
			b=sc.nextBigInteger();
			System.out.println(a.add(b));
		}
		sc.close();
	}
}
