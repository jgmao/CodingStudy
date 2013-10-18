//1.2
//Think about in place method in Java
public class reverseCstring {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println(reverseCstring("123qwe"));
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
