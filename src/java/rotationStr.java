//1.8	
public class rotationStr {
	
	//pre exist method
	public boolean isSubstring(String substr, String str){
		//pre exist method
		boolean issub = true;
		return issub;
	}
	
	public boolean isRotation(String str1, String str2){
		if(str1.length()!=str2.length()) return false;
		else{
			String str1p1 = str1 + str1;
			return isSubstring(str2, str1p1);
		}
	}
}
