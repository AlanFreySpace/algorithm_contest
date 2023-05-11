package week5;

import week1.ListNode;

public class p86 {
	public ListNode partition(ListNode head, int x) {
	       ListNode small_dummy=new ListNode(-1),big_dummy=new ListNode(-1);
	       ListNode small_cur=small_dummy,big_cur=big_dummy,cur=head;

	       while(cur!=null){
	           if(cur.val<x){
	               small_cur.next=cur;
	               small_cur=cur;
	           }else{
	               big_cur.next=cur;
	               big_cur=cur;
	           }
	           cur=cur.next;
	       }

	       if(small_dummy.next!=null){
	           small_cur.next=big_dummy.next;
	           return small_dummy.next;
	       }

	       return big_dummy.next;
	    }
}
