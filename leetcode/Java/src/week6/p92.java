package week6;

import week1.ListNode;

public class p92 {
	public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy=new ListNode(-1,head),cur=dummy;
        ListNode before_left=null,left_node=null;
        int i=1;

        while(i<left){
            cur=cur.next;
            i++;
        }
        before_left=cur;
        cur=cur.next;
        left_node=cur;
        i++;//此时i==left+1

        ListNode before_cur=cur,after_cur=null;
        cur=cur.next;
        while(i<=right){
            after_cur=cur.next;
            cur.next=before_cur;
            before_cur=cur;
            cur=after_cur;
            i++;
        }

        before_left.next=before_cur;
        left_node.next=cur;

        return dummy.next;
    }
}
