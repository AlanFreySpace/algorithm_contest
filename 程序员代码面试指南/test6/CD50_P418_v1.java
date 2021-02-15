package test6;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
/*
 * 贪心的思想解决该问题，首先声明一个项目类，每个项目包含
 * 花费cost及利润profit，声明小根堆：cost小优先
 * 声明大根堆：profit大优先
 * 
 * 每一次选择项目时采取的贪心策略：从小根堆中选出cost<=
 * 当前手头资金的项目，再将这些项目放入大根堆，也就是
 * 待选项目中利润最大的优先完成
 */
class program{
    public int cost;
    public int profit;
    public program(int c,int p){
        this.cost=c;
        this.profit=p;
    }
}

class minCostComp implements Comparator<program>{
    @Override
    public int compare(program p1,program p2){
        return p1.cost-p2.cost;
    }
}

class maxProfitComp implements Comparator<program>{
    @Override
    public int compare(program p1,program p2){
        return p2.profit-p1.profit;
    }
}

public class CD50_P418_v1{
    public long getMaxProfit(int[] costs,int[] profits,long W,int K){
        PriorityQueue<program> minC=new PriorityQueue<program>(new minCostComp());
        PriorityQueue<program> maxP=new PriorityQueue<program>(new maxProfitComp());
        for(int i=0;i<costs.length;i++)
            minC.add(new program(costs[i],profits[i]));
        for(int i=0;i<K;i++){
            while(!minC.isEmpty()&&minC.peek().cost<=W)
                maxP.add(minC.poll());
            if(maxP.isEmpty())
                return W;
            W+=maxP.poll().profit;
        }
        return W;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        long W=sc.nextLong();
        int K=sc.nextInt();
        int[] costs=new int[N];
        int[] profits=new int[N];
        for(int i=0;i<N;i++)
            costs[i]=sc.nextInt();
        for(int i=0;i<N;i++)
            profits[i]=sc.nextInt();
        CD50_P418_v1 ma=new CD50_P418_v1();
        System.out.print(ma.getMaxProfit(costs,profits,W,K));
        sc.close();
    }
}
