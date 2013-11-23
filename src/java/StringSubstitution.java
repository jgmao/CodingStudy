package challenge;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class StringSubstitution {
	String str;
	String[] patterns;
	String output;
	public StringSubstitution(String input){
		str = input.substring(0, input.indexOf(";"));
		String p = input.substring(input.indexOf(";")+1);
		patterns = p.split(",");
		if(patterns.length%2!=0) System.out.println("Input is wrong!!!!!!!!");
		output = str;
	}
	public static void main(String[] args){
		if(args.length>0){
			try {
				FileReader file = new FileReader(args[0]);
				BufferedReader br = new BufferedReader(file);
				String line;
				while((line = br.readLine())!=null){
					StringSubstitution ss = new StringSubstitution(line);
					System.out.println(ss.replacePatterns());
				}
			} catch (FileNotFoundException e) {
				System.out.println("File not found.");
				return;
			} catch (IOException e) {
				System.out.println("Input is wrong!!!!!!!!");
			}
		}
		else System.out.println("Please tell me the input file path.");

	}
	public String replacePatterns(){
		if(patterns.length%2!=0) return "";
		char[] chars = str.toCharArray();
		for(int i=0; i<patterns.length-1;i += 2){
			int idx = 0;
			while(idx!=-1){
				idx = str.indexOf(patterns[i], idx);

				if(idx!=-1){
					for(int j=0; j<patterns[i].length();j++)
						chars[idx+j] = '$';

					output = output.substring(0, idx) + patterns[i+1] + output.substring(idx+patterns[i].length());
					str=String.valueOf(chars);
				}
			}
		}
		return output;
	}
	
}
