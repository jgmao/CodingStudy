import java.util.HashSet;
import java.util.Set;
//2.5
//solution wrong? how about the start node is in odd location of linked list?
//assume I can use other ADT
public class loopStartNode {
	public Node startLoop(Node head){
		Set<Node> nodes = new HashSet<Node>();
		while(head!=null){
			if(nodes.contains(head))
				return head;
			nodes.add(head);
			head = head.next;
		}
		return null;
	}
}
