import java.util.*;
import java.io.*;
public class CCC20S2 {

	static class pair{
		int x,y;
		public pair(int a, int b) {
			x = a;
			y = b;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastReader sc = new FastReader();
		int r = sc.nextInt(), c = sc.nextInt();
		int[][] map = new int[r][c];
		boolean[] vis = new boolean[1000001];
		boolean[][] d = new boolean[r][c];
		for(int i = 0; i<r; i++) {
			for(int j = 0; j<c; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		LinkedList<pair> q = new LinkedList<>();
		d[0][0] = true;
		q.add(new pair(0,0));
		while(!q.isEmpty()) {
			pair cur = q.poll();
			if(d[r-1][c-1]) {
				break;
			}
			int loc = map[cur.x][cur.y];
			if(!vis[loc]) {
				for(int i = 1; i<=(int)Math.sqrt(loc); i++) {
					if(loc%i==0) {
						if(loc/i-1<c&&loc/i-1>=0&&i-1>=0&&i-1<r&&!d[i-1][loc/i-1]) {
	//						System.out.println(i+" "+loc/i);
							q.add(new pair(i-1, loc/i-1));
							d[i-1][loc/i-1] = true;
						}
						if(loc/i-1<r&&loc/i-1>=0&&i-1>=0&&i-1<c&&!d[loc/i-1][i-1]) {
	//						System.out.println(loc/i+" "+i);
							q.add(new pair(loc/i-1, i-1));
							d[loc/i-1][i-1] = true;
						}
					}
				}
				vis[loc] = true;
			}
		}
		System.out.println(d[r-1][c-1]?"yes":"no");
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