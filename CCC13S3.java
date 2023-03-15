import java.util.*;
import java.io.*;
public class CCC13S3 {

	public static class pair{
		int x,y;
		public pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static int t;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastReader sc = new FastReader();
		t = sc.nextInt();
		boolean[] games = new boolean[6];
		int[] scores = new int[5];
		int g = sc.nextInt();
		for(int i = 0; i<g; i++){
			int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
			if(a==1){
				if(b==2){
					games[0] = true;
				}
				else if(b==3) games[1] = true;
				else games[2] = true;
			}
			else if(a==2){
				if(b==3) games[3] = true;
				else if(b==4) games[4] = true;
			}
			else games[5] = true;
			if(c>d)scores[a]+=3;
			else if(c==d){
				scores[a]++;
				scores[b]++;
			}
			else{
				scores[b]+=3;
			}
		}
		boolean[] clone = games.clone();
		int[] score = scores.clone();
//		for(int i = 1;i<5; i++)System.out.print(score[i]+" ");
//		System.out.println();
		solve(clone, score);
		System.out.println(count);
	}
	static int count = 0;
	static void solve(boolean[] games, int[] scores){
//		for(int i = 1; i<5; i++){
//			System.out.print(scores[i]+" ");
//		}
//		System.out.println();
//		for(int i = 0; i<games.length; i++){
//			System.out.print(games[i]+" ");
//		}
//		System.out.println();
		boolean go = true;
		for(int i = 0; i<6; i++){
			if(!games[i]){
				go = false;
				break;
			}
		}
		if(go){
			int team=0, score = 0;
			for(int i = 1; i<5; i++){
				if(score<scores[i]){
					score = scores[i];
					team = i;
				}
			}
			if(team==t){
				count++;
				for(int i = 1; i<5; i++){
					if(scores[i]==score&&i!=team){ 
						count--;
						break;
					}
				}
			}
			return;
		}
		for(int i = 0; i<6; i++){
			if(!games[i]){
				boolean[] clone = games.clone();
				int[] score = scores.clone();
				clone[i] = true;
				int a,b;
				if(i==0){
					a=1;b=2;
				}
				else if(i==1){
					a=1;b=3;
				}
				else if(i==2){
					a=1;b=4;
				}
				else if(i==3){
					a=2;b=3;
				}
				else if(i==4){
					a=2;b=4;
				}
				else{
					a=3;b=4;
				}
				score[a]+=3;
				solve(clone, score);
				score[a]-=2;
				score[b]++;
				solve(clone,score);
				score[a]--;
				score[b]+=2;
				solve(clone,score);
				return;
			}
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