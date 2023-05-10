package week5;

import week1.ListNode;

public class p82 {
	public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy=new ListNode(-1,head);//哨兵节点
        ListNode before=dummy;
        while(before.next!=null){
            ListNode cur=before.next.next;
            while(cur!=null&&cur.val==before.next.val) cur=cur.next;
            //注意这种判断是否有重复元素的方法 before.next.next==cur
            if(before.next.next==cur) before=before.next;
            else before.next=cur;
        }
        return dummy.next;
    }
}
