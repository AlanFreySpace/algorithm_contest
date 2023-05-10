package week5;

import week1.ListNode;

public class p83 {
	// 与82题的思路是完全相同的
	public ListNode deleteDuplicates(ListNode head) {
        ListNode before=head;
        while(before!=null){
            ListNode cur=before.next;
            while(cur!=null&&cur.val==before.val) cur=cur.next;
            if(before.next==cur) before=before.next;
            else before.next=cur;
        }
        return head;
    }
}
