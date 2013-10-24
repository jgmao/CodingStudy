//2.3
public class removeMidNode {
	public void removeMid(Node mid){
		Node next = mid.next;
		mid.value = next.value;
		mid.next = next.next;
	}
}
