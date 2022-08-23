package week2;

import java.util.PriorityQueue;
import java.util.Comparator;

public class p23 {
	public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy=new ListNode(-1),tail=dummy;
        PriorityQueue<ListNode> pq=new PriorityQueue<>(
            new Comparator<ListNode>(){
                @Override
                public int compare(ListNode l1,ListNode l2){
                    return l1.val-l2.val;
                }
            }
        );

        for(int i=0;i<lists.length;i++)
            if(lists[i]!=null) pq.add(lists[i]);

        while(pq.size()!=0){
            ListNode now=pq.peek();
            pq.poll();
            tail=tail.next=now;
            if(now.next!=null) pq.add(now.next);
        }

        return dummy.next;
    }
}
