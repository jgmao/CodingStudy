import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

//4.2
class GraphNode{
	ArrayList<GraphNode> next;
}
public class isRoute {
	public boolean isroute(GraphNode start, GraphNode target){
		if(start.equals(target)) return true;
		ArrayList<GraphNode> visited = new ArrayList<GraphNode>();
		Stack<GraphNode> stack = new Stack<GraphNode>();
		stack.add(start);
		while(!stack.isEmpty()){
			GraphNode node = stack.pop();
			visited.add(start);
			Iterator<GraphNode> neighbors = node.next.iterator();
			while(neighbors.hasNext()){
				GraphNode neighbor = neighbors.next();
				if(neighbor.equals(target)) return true;
				if(!visited.contains(neighbor)){ 
					visited.add(neighbor);
					stack.add(neighbor);
				}
			}			
		}
		return false;
	}
}
