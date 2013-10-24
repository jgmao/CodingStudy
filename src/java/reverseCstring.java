import java.util.ArrayList;
import java.util.Stack;

//1.2
//Think about in place method in Java
public class reverseCstring {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//System.out.println(reverseCstring("123qwe"));
		ArrayList<String> s = new ArrayList<String>();
		s.add("a");
		s.add("c");
		s.add("b");
		Stack<String> ss = new Stack<String>();
		ss.push("c");
		System.out.println(ss.containsAll(s));
	}
	public static String reverseCstring(String str){
		StringBuffer buffer = new StringBuffer();
		buffer.append('\0');
		for(int i=str.length()-1; i>=0;i--){
			buffer.append(str.charAt(i));
		}
		return buffer.toString();
	}

}
