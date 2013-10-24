import java.util.Stack;

//3.4
public class hanoiTower {
	Stack<Integer> from, to, buffer;
	public void moveith(int i, Stack<Integer> from, Stack<Integer> to, Stack<Integer> buffer){
		
		if(i>0){
			this.from = from;
			this.to = to;
			this.buffer =buffer;
			moveith(i-1, from, buffer, to);
			int disk = from.pop();
			to.push(disk);
			moveith(i-1, buffer, to, from);
		}
	}
}
