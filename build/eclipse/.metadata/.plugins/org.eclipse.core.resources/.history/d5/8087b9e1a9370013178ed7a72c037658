//1.1
public class uniqueChar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println(uniqueChar("abcdsd"));
	}
	public static boolean uniqueChar(String s){
		int check = 0;
		for(int i=0;i<s.length();i++){
			int c = 1<<(s.charAt(i) - 'a');
			if((check & c) > 0) return false;
			check |= c;
			
		}
		return true;
	}

}
