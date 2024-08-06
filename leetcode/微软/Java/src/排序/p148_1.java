package 排序;

public class p148_1 {
	public ListNode sortList(ListNode head) {
        int n=0;
        for(ListNode p=head; p!=null; p=p.next) {
            n++;
        }

        ListNode dummy = new ListNode(-1,head);
        for(int i=1; i<n; i*=2) {
            ListNode cur = dummy;
            for(int j=1; j+i<=n; j+=2*i) {
                ListNode p = cur.next, q=p;
                for(int k=0; k<i; k++) {
                    q = q.next;
                }

                int l=0, r=0;
                while(q!=null && l<i && r<i) {
                    if(p.val > q.val) {
                        cur.next = q;
                        cur = q;
                        q = q.next;
                        r++;
                    } else {
                        cur.next = p;
                        cur = p;
                        p = p.next;
                        l++;
                    }
                }

                while(l<i) {
                    cur.next = p;
                    cur = p;
                    p = p.next;
                    l++;
                }
                while(r<i && q!=null) {
                    cur.next = q;
                    cur = q;
                    q = q.next;
                    r++;
                }

                cur.next = q;
            }
        }

        return dummy.next;
    }
}
