import java.util.HashMap;
import java.util.Set;

//1.4
//Two solutions cannot be right. Think about this case "aaaaaab" and "aabaaa"
public class twoanagramstring {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
System.out.println(anagram("sbcab","acsba"));
	}
	public static boolean anagram(String s1, String s2){
		//method one is comparing after sort two strings
		//this is another method
		HashMap<Character, Integer> counts = new HashMap<Character, Integer>();
		for(int i=0; i<s1.length(); i++){
			Character c = s1.charAt(i);
			if(counts.containsKey(c)) counts.put(c, counts.get(c)+1);
			else counts.put(c, 1);
		}
		for(int j=0; j<s2.length(); j++){
			Character c = s2.charAt(j);
			if(counts.containsKey(c)){
				if(counts.get(c)==1)
					counts.remove(c);
				else counts.put(c, counts.get(c)-1);
			}
			else return false;
		}
		return counts.isEmpty();
	}
}
