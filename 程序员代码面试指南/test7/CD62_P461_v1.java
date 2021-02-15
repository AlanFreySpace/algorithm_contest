package test7;

import java.util.HashMap;
import java.util.Scanner;

/*
 * 利用时间戳解决setAll问题
 */
class myValue<V>{
    private V value;
    private int time;
    public myValue(V v,int t){
        this.value=v;
        this.time=t;
    }
    public V getValue(){
        return this.value;
    }
    public int getTime(){
        return this.time;
    }
}

class myHashMap<K,V>{
    private HashMap<K,myValue<V>> baseMap=new HashMap<>();
    private int time=0;
    private myValue<V> setAll=new myValue<V>(null,-1);
    
    public boolean containsKey(K key){
        return this.baseMap.containsKey(key);
    }
    
    public void put(K key,V value){
        this.baseMap.put(key,new myValue<V>(value,this.time++));
    }
    
    public void setAll(V value){
        this.setAll=new myValue<V>(value,time++);
    }
    
    public V get(K key){
        if(this.containsKey(key)){
            if(this.baseMap.get(key).getTime()>this.setAll.getTime())
                return this.baseMap.get(key).getValue();
            else
                return this.setAll.getValue();
        }
        else{
            return null;
        }
    }
}

public class CD62_P461_v1{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        myHashMap<Integer,Integer> myMap=new myHashMap<>();
        for(int i=0;i<N;i++){
            int opt=sc.nextInt();
            if(opt==1)
                myMap.put(sc.nextInt(),sc.nextInt());
            else if(opt==2){
                Integer ans=myMap.get(sc.nextInt());
                if(ans!=null)
                    System.out.println(ans);
                else
                    System.out.println(-1);
            }
            else
                myMap.setAll(sc.nextInt());
        }
        sc.close();
    }
}