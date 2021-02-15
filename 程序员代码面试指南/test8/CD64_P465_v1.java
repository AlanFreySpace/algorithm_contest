package test8;

import java.util.HashMap;
import java.util.Scanner;

//双向链表中的节点
class Node<V>{
    public V value;
    public Node<V> last;
    public Node<V> next;
    
    public Node(V value){
        this.value=value;
    }
}

//双向链表
class doubleLinkedList<V>{
    private Node<V> head;
    private Node<V> tail;
    
    public doubleLinkedList(){
        this.head=null;
        this.tail=null;
    }
    
    public void addNodeToTail(Node<V> node){
        if(node==null)
            return;
        if(this.head==null){
            this.head=node;
            this.tail=node;
        }
        else{
            this.tail.next=node;
            node.last=this.tail;
            this.tail=node;
        }
    }
    
    public void moveNodeToTail(Node<V> node){
        if(node==this.tail)
            return;
        if(node==this.head){
            node.next.last=null;
            this.head=node.next;
        }
        else{
            node.last.next=node.next;
            node.next.last=node.last;
        }
        this.tail.next=node;
        node.last=this.tail;
        node.next=null;
        this.tail=node;
    }
    
    public Node<V> removeHead(){
        if(this.head==null)
            return null;
        Node<V> res=this.head;
        if(this.head==this.tail){
            this.head=null;
            this.tail=null;
        }else{
            this.head=this.head.next;
            res.next=null;
            this.head.last=null;
        }
        return res;
    }
}

//LRU缓存结构
class MyCache<K,V>{
    private HashMap<K,Node<V>> keyValueMap;
    private HashMap<Node<V>,K> valueKeyMap;
    private doubleLinkedList<V> list;
    private int capacity;
    
    public MyCache(int capacity){
        if(capacity<1)
            throw new RuntimeException("Capacity should be more than 0");
        this.keyValueMap=new HashMap<K,Node<V>>();
        this.valueKeyMap=new HashMap<Node<V>,K>();
        this.list=new doubleLinkedList<V>();
        this.capacity=capacity;
    }
    
    public void removeMostUnusedCache(){
        Node<V> node=this.list.removeHead();
        K key=this.valueKeyMap.get(node);
        this.keyValueMap.remove(key);
        this.valueKeyMap.remove(node);
    }
    
    public void set(K key,V value){
        if(this.keyValueMap.containsKey(key)){
            Node<V> node=this.keyValueMap.get(key);
            node.value=value;
            this.list.moveNodeToTail(node);
        }else{
            Node<V> node=new Node<V>(value);
            this.keyValueMap.put(key,node);
            this.valueKeyMap.put(node,key);
            this.list.addNodeToTail(node);
            if(this.capacity+1==this.keyValueMap.size())
                removeMostUnusedCache();
        }
    }
    
    public V get(K key){
        if(this.keyValueMap.containsKey(key)){
            Node<V> node=this.keyValueMap.get(key);
            this.list.moveNodeToTail(node);
            return node.value;
        }
        return null;
    }
}

public class CD64_P465_v1{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int K=sc.nextInt();
        int opt=0;
        MyCache<Integer,Integer> cache=new MyCache<Integer,Integer>(K);
        for(int i=0;i<N;i++){
            opt=sc.nextInt();
            if(opt==1)
                cache.set(sc.nextInt(),sc.nextInt());
            else{
                Integer res=cache.get(sc.nextInt());
                if(res==null)
                    System.out.println(-1);
                else
                    System.out.println(res);
            }
        }
        sc.close();
    }
}
