//2.2
public class NthLastNode {
	public Node nthelement(Node head, int n){
		int len = 0;
		Node measureLen = head;
		do{
			len++;
			measureLen = measureLen.next;
		}while(measureLen.next!=null);
		for(int i =0; i< len-n; i++){
			head = head.next;
		}
		return head;
	}
}
