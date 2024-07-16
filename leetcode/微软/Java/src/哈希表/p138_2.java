package 哈希表;

public class p138_2 {
	public Node copyRandomList(Node head) {
        if(head == null) {
            return null;
        }

        Node cur = head;
        while(cur != null) {
            Node newCur = new Node(cur.val);
            newCur.next = cur.next;
            cur.next = newCur;
            cur = newCur.next;
        }

        cur = head;
        Node ans = head.next;
        while(cur != null) {
            Node newCur = cur.next;
            if(cur.random != null) {
                newCur.random = cur.random.next;
            }
            cur = newCur.next;
        }

        cur = head;
        while(cur != null) {
            Node newCur = cur.next, oriNext = newCur.next;
            cur.next = oriNext;
            if(oriNext != null) {
                newCur.next = oriNext.next;
            }
            cur = oriNext;
        }

        return ans;
    }
}
