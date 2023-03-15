import java.io.*;
import java.util.*;

public class CCC03S4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastReader sc = new FastReader();
		int n = sc.nextInt();
		for(int t = 0; t<n; t++){
			String a = sc.nextLine();
			String[] suffixArr = new String[a.length()];
			for(int i = 0; i<suffixArr.length; i++){
				suffixArr[i] = a;
				a = a.substring(1, a.length());
			}
			Arrays.sort(suffixArr);
//			for(String i : suffixArr)System.out.print(i+" ");
//			System.out.println();
			int count = suffixArr[0].length();
			for(int i = 0; i<suffixArr.length-1; i++){
				count += suffixArr[i+1].length() - removePrefix(suffixArr[i], suffixArr[i+1]);
			}
			System.out.println(count+1);
		}
	}
	static int removePrefix(String a, String b){
		int count = 0;
		for(int i = 0; i<Math.min(a.length(), b.length()); i++){ //removes the common prefix from the new string
			if(a.charAt(i)!=b.charAt(i)) break;
			count++;
		}
//		System.out.println(count);
		return count;
	}
	public static class FastReader {
	    BufferedReader br;
	    StringTokenizer st;
	    public FastReader() {
	    	br = new BufferedReader(new InputStreamReader(System.in));
	    }
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
		        } catch (IOException e) {
		        	e.printStackTrace();
		        }
			}
			return st.nextToken();
	    }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = null;
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}