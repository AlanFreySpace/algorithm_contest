package test;
import java.math.BigInteger;
import java.util.Scanner;
/*
 * Java高精度计算:BigDecimal(表示浮点数)和 BigInteger(表示整数)
 * 1.valueOf(parament); 将参数转换为指定类型 
 * 2. add(); 大数加法 
 * 3. substract(); 减法 
 * 4. multiply(); 乘法 
 * 5. divided(); 相除取整 
 * 6. remainder(); 取余 
 * 7. pow(); a.pow(b) = a ^ b 
 * 8. gcd(); 最大公约数 
 * 9. abs(); 绝对值 
 * 10. negate(); 取反数 
 * 11. mod(); a.mod(b) = a % b = a.remainder(b) 
 * 12. max(); min(); 
 * 13. public int compareTo(); 比较 
 * 14. boolean equals(); 比较是否相等
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
