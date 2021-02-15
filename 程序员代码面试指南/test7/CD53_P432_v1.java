package test7;

import java.util.Scanner;

public class CD53_P432_v1{
	//得到纯能值数组
    public int changeDisGetInit(int[] oil,int[] dis){
        int init=-1;
        for(int i=0;i<oil.length;i++){
            dis[i]=oil[i]-dis[i];
            if(dis[i]>=0)
                init=i;
        }
        return init;
    }
    //上一个位置
    public int lastIndex(int index,int size){
        return index==0?size-1:index-1;
    }
    //下一个位置
    public int nextIndex(int index,int size){
        return index==size-1?0:index+1;
    }
    /*
     * need是需要dis[start]补充的能量值，其值总
     * 大于等于0
     */
    public void connectGood(int[] dis,int start,int init,int[] res){
        long need=0;
        while(start!=init){
            if(dis[start]<need)
                need-=dis[start];
            else{
                need=0;
                res[start]=1;
            }
            start=lastIndex(start,dis.length);
        }
    }
    
    public int[] getGoodPoint(int[] oil,int[] dis){
        int init=changeDisGetInit(oil,dis);
        int[] res=new int[dis.length];
        if(init==-1)
            return res;
        int start=init,end=nextIndex(init,dis.length);
        long need=0,rest=0;
        do{
        	/*
        	 * 该if即书上例子1的情况，注意end点的值当前
        	 * 并未被考虑，这种情况发生时，是之前产生了
        	 * 一个[start,end)区域，该区域累加了[start,end)的
        	 * 纯能值，并且这个累加和小于0(当前rest小于0)，因此不断
        	 * 尝试新的start,尝试将rest补足到大于等于0，这个start
        	 * 最多可以尝试到end位置
        	 */
            if(start!=init&&lastIndex(end,dis.length)==start)
                break;
            /*
             * 当前需求燃料为need，需要dis[start]来补充，但
             * 当前start点纯能值过小，只能部分补充(或使得need需求
             * 更大)
             */
            if(need>dis[start])
                need-=dis[start];
            /*
             * 当前start点可完全补充需求的燃料，且可剩下燃料，
             * 供正向扩充使用(need是反向，也就是离start点近的点
             * 需求的燃料，其优先级自然比rest，也就是正向扩充
             * 的，离start远的点优先级高)
             */
            else{
                rest+=(dis[start]-need);
                need=0;
                /*
                 * 向正向扩充，扩充结束后有两种情况：
                 * 1.扩充到某点时，rest<0，此时end=这点的下一个点(
                 * 此时end点的值还未被考虑，可见符合开区间的定义)，这时需要尝试
                 * 反向扩充，补足rest
                 * 2.扩充到start==end,此时所有的值都被累加了，说明
                 * 找到一个良好出发点，此时只需进入connectGood过程，考虑[start+1,
                 * init)这些点即可。
                 */
                while(rest>=0&&start!=end){
                    rest+=dis[end];
                    end=nextIndex(end,dis.length);
                }
                if(rest>=0){
                    res[start]=1;
                    connectGood(dis,lastIndex(start,dis.length),init,res);
                    break;
                }
            }
            start=lastIndex(start,dis.length);
        }while(start!=init);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] oil=new int[N];
        int[] dis=new int[N];
        for(int i=0;i<N;i++)
            oil[i]=sc.nextInt();
        for(int i=0;i<N;i++)
            dis[i]=sc.nextInt();
        CD53_P432_v1 ma=new CD53_P432_v1();
        int[] res=ma.getGoodPoint(oil,dis);
        for(int i=0;i<N;i++)
            System.out.print(res[i]+" ");
        sc.close();
    }
}