//3.2
class NodeWMin{
	int value;
	int min;
	NodeWMin next;
	public NodeWMin(int v){
		value = v;
		min = min<v ? min:v;
	}
}
public class findMinStack {
	NodeWMin top;
	public void push(int n){
		NodeWMin node = new NodeWMin(n);
		node.next = top;
		top = node;
	}
	public int pop(){
		int value = top.value;
		top = top.next;
		return value;
	}
	public int min(){
		return top.min;
	}
	
}
