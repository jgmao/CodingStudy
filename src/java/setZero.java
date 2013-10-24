import java.util.Iterator;
import java.util.PriorityQueue;

//1.7
//solution seems not right
//test priorityqueue for 3.6
public class setZero {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		q.add(3);
		q.add(1);
		q.add(2);
		Iterator<Integer> it = q.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
	}
	
	public void setzero(int[][] matrix, int m, int n){
		int[] column = new int[m];
		int[] row = new int[n];
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(matrix[i][j]==0){
					column[i]=1;
					row[j]=1;
				}
			}
		}

		for(int i=0; i<m; i++){
			if (column[i]==1){
				for(int j=0; j<n; j++) matrix[i][j]=0;			
			}
		}
		for(int i=0; i<n; i++){
			if (row[i]==1){
				for(int j=0; j<n; j++) matrix[j][i]=0;			
			}
		}
	}

}
