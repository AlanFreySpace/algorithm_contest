package week6;

import week1.ListNode;

public class p92 {
	public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy=new ListNode(-1,head),before=null,after=null,cur=dummy;
        int i=1;
        while(i<left){
            cur=cur.next;
            i++;
        }
        before=cur;
        ListNode next1=cur;
        while(i<right){
            cur=next1;
            next1=cur.next;
        }
    }
}
