package week4;

public class p61 {
	public ListNode rotateRight(ListNode head, int k) {
        if(head==null||k==0) return head;
        ListNode cur=head,oldEnd=null;
        int len=0;

        while(cur!=null){
            oldEnd=cur;
            cur=cur.next;
            len++;
        }
        if(len<=k) k=k%len;
        if(k==0) return head;

        cur=head;
        for(int i=1;i<len-k;i++) cur=cur.next;
        ListNode newHead=cur.next;
        oldEnd.next=head;
        cur.next=null;

        return newHead;
    }
	
	
	 class ListNode {
	    int val;
	    ListNode next;
	    ListNode() {}
	    ListNode(int val) { this.val = val; }
	    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
	 }
}
