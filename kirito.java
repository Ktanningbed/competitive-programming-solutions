import java.util.*;
import java.io.*;
public class kirito {
	static int n,m;
	static long[][] hash = new long[2001][5001];
	static long mod = (int)1e9+7;
	
	static int check(int t, int b) {
		int l = 0, r = m;
		loop:
		while(l<r-1) {
			int mid = (r+l)/2;
			long cur = hash[t][mid];
			for(int i = t+1; i<=b; i++) {
				if(cur!=hash[i][mid]) {
					r = mid;
					continue loop;
				}
			}
			l = mid;
		}
		long cur = hash[t][l];
		for(int i = t+1; i<=b; i++) {
			if(hash[i][l]!=cur) {
				return -1;
			}
		}
		return l;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastReader sc = new FastReader();
		n = sc.nextInt();m = sc.nextInt();
		for(int i = 0; i<n; i++) {
			String input = sc.nextLine();
			for(int j = 0; j<m; j++) {
				if(j==0) hash[i][j] = Character.getNumericValue(input.charAt(j));
				else hash[i][j] = ((hash[i][j-1]*2)%mod+Character.getNumericValue(input.charAt(j)))%mod;
			}
		}
		int q = sc.nextInt();
		for(int i = 0; i<q; i++) {
			int t = sc.nextInt()-1, b = sc.nextInt()-1;
			int c = check(t,b)+1;
			System.out.println(c!=0?c*(b+1-t):c);
			long[] temp = hash[t];
			hash[t] = hash[b];
			hash[b] = temp;
			
		}
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