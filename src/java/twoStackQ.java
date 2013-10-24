import java.util.PriorityQueue;
import java.util.Stack;

//3.5
public class twoStackQ {
	Stack<Object> s1;
	Stack<Object> s2;
	public void push(Object o){
		s1.push(o);
	}
	public Object pop(){
		for(int i=0; i<s1.size();i++)
			s2.push(s1.pop());
		return s2.pop();
	}
	public Object peek(){
		for(int i=0; i<s1.size();i++)
			s2.push(s1.pop());
		PriorityQueue q;
		return s2.peek();
	}
}
