import java.util.ArrayList;
import java.util.Stack;

//3.3

public class setOfStacks {
	ArrayList<Stack> stacks = new ArrayList<Stack>();
	int threshold;
	public setOfStacks(int n){
		threshold = n;
	}
	public Object pop(){
		if (stacks.isEmpty()) return null;
		Stack current = stacks.get(stacks.size()-1);
		Object data = current.pop();
		if(current.isEmpty())
			stacks.remove(stacks.size()-1);
		return data;			
	}
	public void push(Object o){
		if (stacks.isEmpty() || (stacks.get(stacks.size()-1).size()==threshold)){
			Stack newStack = new Stack();
			newStack.push(o);
			stacks.add(newStack);
		}
		else{
			stacks.get(stacks.size()-1).push(o);
		}
	}
	public Object popAt(int num){
		Object data = stacks.get(num).pop();
		for(int i=num; i<stacks.size();i++){
			Stack stack = stacks.get(i+1);
			if(!stack.isEmpty()){
				Object mo = stack.get(threshold-1);
				stacks.get(i).push(mo);
				stack.remove(threshold-1);
			}
		}
		return data;
	}

}
