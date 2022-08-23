package week2;

public class p25 {
	public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy=new ListNode(-1,head);

        ListNode p=dummy,q=p;
        while(p!=null){
            for(int i=0;i<k&&q!=null;i++) q=q.next;
            if(q==null) break;

            ListNode a=p.next,b=a.next;
            for(int i=0;i<k-1;i++){
                ListNode c=b.next;
                b.next=a;
                a=b;
                b=c;
            }

            ListNode d=p.next;
            p.next=a;
            d.next=b;
            p=q=d;
        }

        return dummy.next;
    }
}
