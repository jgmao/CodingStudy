package challenge;

import java.util.ArrayList;


public class UglyNumber {
	static ArrayList<ArrayList<Integer>> ref = new ArrayList<ArrayList<Integer>>();
	static int[] digits;
	public long uglyNumber(String num){
		long total = 0;
		digits = new int[num.length()];
		
		for(int i =0; i<num.length(); i++)
			digits[i]=Character.getNumericValue(num.charAt(i));
		calc();
		for(int item:ref.get(0))
			if(testUgly(item)) total += 1;		
		return total;
	}
	public void calc(){
		ArrayList<Integer> sums =new ArrayList<Integer>();
		if(digits.length==1){
			sums.add(digits[0]);
			ref.add(0, sums);
		}
		else{
			for(int i=0;i<digits.length-1;i++){
				int value = (i==0 ? 0:digits[digits.length-1-i]);
				ref.add(digits.length-1-i, shifting(digits.length-1-i, value));
			}
		}
	}
	public ArrayList<Integer> shifting(int idx, int c){
		ArrayList<Integer> sums =new ArrayList<Integer>();
		for(int i=1; i<digits.length-idx; i++){				
			ArrayList<Integer> pre = ref.get(idx+i);
			for(Integer j:pre){
				sums.add(j+c);
				sums.add(c-j);
			}
			c = c*10 +  digits[idx+i]; 
			sums.addAll(shifting(idx+i, c));
		}
		return sums;
	}

	public boolean testUgly(int n){
		if(n==0) return true;
		if(n%2==0 || n%3==0 || n%5==0 ||n%7==0)
			return true;
		else return false;
	}

}
