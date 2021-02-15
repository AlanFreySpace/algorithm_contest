package test7;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

class Node{
    public int x;
    public boolean isAdd;
    public int h;
    public Node(int v1,boolean v2,int v3){
        this.x=v1;
        this.isAdd=v2;
        this.h=v3;
    }
}

class NodeComparator implements Comparator<Node>{
    @Override
    public int compare(Node n1,Node n2){
        return n1.x-n2.x;
    }
}

public class CD52_P423_v1{
    public List<List<Integer>> getOutline(int[][] m){
        Node[] nodes=new Node[2*m.length];
        for(int i=0;i<m.length;i++){
            nodes[2*i]=new Node(m[i][0],true,m[i][2]);
            nodes[2*i+1]=new Node(m[i][1],false,m[i][2]);
        }
        Arrays.sort(nodes,new NodeComparator());
        
        /*
         * 得到mapHeightTimes及mapXMaxHeight，
         * mapHeightTimes用于辅助创建mapXMaxHeight
         * mapHeightTimes代表当前位置有哪些高度出现，
         * mapXMaxHeight代表当前位置最高高度。
         */
        TreeMap<Integer,Integer> mapHeightTimes=new TreeMap<>();
        TreeMap<Integer,Integer> mapXMaxHeight=new TreeMap<>();
        for(int i=0;i<nodes.length;i++){
            if(nodes[i].isAdd){
                if(!mapHeightTimes.containsKey(nodes[i].h))
                    mapHeightTimes.put(nodes[i].h,1);
                else
                    mapHeightTimes.put(nodes[i].h,mapHeightTimes.get(nodes[i].h)+1);
            }
            else{
                if(mapHeightTimes.get(nodes[i].h)==1)
                    mapHeightTimes.remove(nodes[i].h);
                else
                    mapHeightTimes.put(nodes[i].h,mapHeightTimes.get(nodes[i].h)-1);
            }
            
            if(mapHeightTimes.isEmpty())
                mapXMaxHeight.put(nodes[i].x,0);
            else
                mapXMaxHeight.put(nodes[i].x,mapHeightTimes.lastKey());
        }
        /*
         * 利用mapXMaxHeight构建大楼轮廓
         */
        List<List<Integer>> res=new ArrayList<>();
        int preHeight=0,start=0;
        int curX,curHeight;
        for(Entry<Integer,Integer> entry:mapXMaxHeight.entrySet()){
            curX=entry.getKey();
            curHeight=entry.getValue();
            if(preHeight!=curHeight){
                if(preHeight!=0)
                    res.add(new ArrayList<>(Arrays.asList(start,curX,preHeight)));
                start=curX;
                preHeight=curHeight;
            }
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[][] m=new int[N][3];
        for(int i=0;i<N;i++)
            for(int j=0;j<3;j++)
                m[i][j]=sc.nextInt();
        CD52_P423_v1 ma=new CD52_P423_v1();
        List<List<Integer>> res=ma.getOutline(m);
        for(int i=0;i<res.size();i++){
            List<Integer> tmp=res.get(i);
            for(int j=0;j<3;j++)
                System.out.print(tmp.get(j)+" ");
            System.out.println();
        }
        sc.close();
    }
}