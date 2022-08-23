package week2;

public class p24 {
	public ListNode swapPairs(ListNode head) {
        ListNode dummy=new ListNode(-1,head);

        ListNode p=dummy;
        while(p.next!=null&&p.next.next!=null){
            ListNode a=p.next,b=p.next.next;
            p.next=b;
            a.next=b.next;
            b.next=a;
            p=a;
        }

        return dummy.next;
    }
}
