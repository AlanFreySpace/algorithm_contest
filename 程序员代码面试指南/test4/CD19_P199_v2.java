package test4;

import java.util.Scanner;

/*
 * 利用记忆化搜索解决问题
 */
public class CD19_P199_v2 {
	public int getNum(int[] arr,int index,int rest,int[][] map){
        if(arr==null||arr.length==0)
            return 0;
        int res=0,mapValue=0;
        if(index==arr.length)
            res=(rest==0?1:0);
        else{
            for(int i=0;i*arr[index]<=rest;i++){
                mapValue=map[index+1][rest-i*arr[index]];
                if(mapValue!=0)
                    res=res+(mapValue==-1?0:mapValue);
                else
                    res=res+getNum(arr,index+1,rest-i*arr[index],map);
            }
        }
        map[index][rest]=(res==0?-1:res);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        int[][] map=new int[n+1][aim+1];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD19_P199_v2 ma=new CD19_P199_v2();
        System.out.print(ma.getNum(arr,0,aim,map));
        sc.close();
    }
}
