import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

//4.1 
//BFS
class TreeNode{
	int value;
	TreeNode lc;
	TreeNode rc;
	TreeNode (int v){
		this.value = v;
	}
}
public class isBalanceTree {
	public int maxHight(TreeNode root){
		if(root==null) return 0;
		return 1+Math.max(maxHight(root.lc), maxHight(root.rc));
	}
	public int minHight(TreeNode root){
		if(root==null) return 0;
		return 1+Math.min(maxHight(root.lc), maxHight(root.rc));
	}
	public boolean isbanlance(TreeNode root){
		return (maxHight(root)-minHight(root)<=1);
	}

}
