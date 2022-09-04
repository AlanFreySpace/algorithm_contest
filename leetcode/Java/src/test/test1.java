package test;

public class test1 {
	 public static void main(String[] main) {
		 int x=10,y=30;
		 do {
			 y-=x;
			 x++;
			 System.out.println(x+" "+y);
		 }while(x++<y--);
	 }
}
