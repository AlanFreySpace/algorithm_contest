package test;
import java.math.BigInteger;
import java.util.Scanner;
/*
 * Java�߾��ȼ���:BigDecimal(��ʾ������)�� BigInteger(��ʾ����)
 * 1.valueOf(parament); ������ת��Ϊָ������ 
 * 2. add(); �����ӷ� 
 * 3. substract(); ���� 
 * 4. multiply(); �˷� 
 * 5. divided(); ���ȡ�� 
 * 6. remainder(); ȡ�� 
 * 7. pow(); a.pow(b) = a ^ b 
 * 8. gcd(); ���Լ�� 
 * 9. abs(); ����ֵ 
 * 10. negate(); ȡ���� 
 * 11. mod(); a.mod(b) = a % b = a.remainder(b) 
 * 12. max(); min(); 
 * 13. public int compareTo(); �Ƚ� 
 * 14. boolean equals(); �Ƚ��Ƿ����
 */
public class t2 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()) {
			BigInteger a,b;
			a=sc.nextBigInteger();
			b=sc.nextBigInteger();
			BigInteger c=a.add(b);
			System.out.println(c);
		}
		sc.close();
	}
}
