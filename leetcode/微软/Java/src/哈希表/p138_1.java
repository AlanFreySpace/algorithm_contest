package 哈希表;

import java.util.HashMap;

public class p138_1 {
	public Node copyRandomList(Node head) {
        if(head == null) {
            return null;
        }

        HashMap<Node,Node> hash = new HashMap<>();
        Node ans = new Node(head.val);
        hash.put(head,ans);

        while(head.next != null) {
            if(!hash.containsKey(head.next)) {
                hash.put(head.next, new Node(head.next.val));
            }
            hash.get(head).next = hash.get(head.next);

            if(head.random != null && !hash.containsKey(head.random)) {
                hash.put(head.random, new Node(head.random.val));
            }
            hash.get(head).random = hash.get(head.random);

            head = head.next;
        }

        hash.get(head).random = hash.get(head.random);
        return ans;
    }
}
