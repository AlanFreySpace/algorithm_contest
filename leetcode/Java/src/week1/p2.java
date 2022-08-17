package week1;

public class p2 {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy=new ListNode(-1),cur=dummy;
        int t=0;
        while(l1!=null||l2!=null||t!=0){
            if(l1!=null){
                t+=l1.val;
                l1=l1.next;
            }
            if(l2!=null){
                t+=l2.val;
                l2=l2.next;
            }
            cur=cur.next=new ListNode(t%10);
            t/=10;
        }
        return dummy.next;
    }
}
