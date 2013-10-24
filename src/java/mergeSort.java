// this is not a good idea, since each swap require O(n) cost, and we need nlogn times swap, the total cost is larger than n^2
import java.util.LinkedList;

//helper for removeDupNode
public class mergeSort {
	LinkedList<Node> list;
 	public void swap(Node n1, Node n2 ){
 		Node temp = list.getFirst();
 		if(temp == n1){
 	 		while(temp.next!=null){
 	 			if(temp.next == n2){
 	 				temp.next = n1;
 	 				break;
 	 			}
 	 			else temp = temp.next;
 	 		}

 		}
 		else if(temp == n2){
 	 		while(temp.next!=null){
 	 			if(temp.next == n1){
 	 				temp.next = n2;
 	 				break;
 	 			}
 	 			else temp = temp.next;
 	 		}

 		}
 		else
	 		while(temp.next!=null){
	 			if(temp.next == n1){
	 				Node n = temp.next;
	 				temp.next = n2;
	 				temp = n;
	 			}
	 			else if(temp.next == n2){
	 				Node n = temp.next;
	 				temp.next = n1;
	 				temp = n;
	 			}
	 			else temp = temp.next;
	 		}
 		temp = n2.next;
 		n2.next = n1.next;
 		n1.next = temp;
 	}
 	public mergeSort (LinkedList<Node> ll){
 		this.list = ll;
 		int len =1;
 		
 	}
}
