package test5;

import java.util.Scanner;

/*
 * ��ŵ������ԭ����Ľ�
 */
public class CD30_P217_v1 {
	/*
	 * process���̱�ʾ��n��Բ�̴�from�ƶ���to�Ĳ��裺
	 * 1.��ֻ��һ��Բ�̣���ֱ�Ӵ�from�ƶ���to����
	 * 2.��Բ�̶���һ����
	 *   �Ƚ�n-1��Բ�̴�from�ƶ�����תԲ��mid��process(n-1,from,to,mid)
	 *   ����n��Բ�̴�from�ƶ���to
	 *   ��n-1��Բ�̴�mid�ƶ���to:process(n-1,mid,from,to);
	 */
	public void process(int n,int from,int mid,int to){
        if(n==1)
            System.out.println("Move "+n+" from "+from+" to "+to);
        else{
            process(n-1,from,to,mid);
            System.out.println("Move "+n+" from "+from+" to "+to);
            process(n-1,mid,from,to);
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        CD30_P217_v1 ma=new CD30_P217_v1();
        ma.process(n,1,2,3);
        sc.close();
    }
}
