package week2;

public class p19 {
	/*
	 * 使用快慢指针解决 与C++中的写法不同 
	 * first是快指针 second是慢指针
	 */
	public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy=new ListNode(-1,head);
        ListNode first=head,second=dummy;

        int i=0;
        while(first!=null){
            first=first.next;
            if(i>=n)
                second=second.next;
            i++;
        }

        second.next=second.next.next;
        return dummy.next;
    }
}

class ListNode {
	int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
