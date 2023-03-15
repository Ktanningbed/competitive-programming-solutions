import java.util.*;
public class CCC11S3 {

	static int[][] c;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		c = new int[5][5];
		for(int i = 0; i<t; i++){
			int m = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			boolean a = solve(m,x,y);
			if(a){
				System.out.println("crystal");
			}
			else{
				System.out.println("empty");
			}
		}
	}
	static boolean solve(int m, int x, int y){
		int x1 = (int) (x/Math.pow(5, m-1));
		int y1 = (int) (y/Math.pow(5, m-1));
		int xx = (int) (x % Math.pow(5, m-1));
		int yy = (int) (y % Math.pow(5, m-1));
		if(m==1){
			if(((x1>=1 && x1<=3) && (y==0))||(x1==2 && y==1)){
				return true;
			}
			return false;
		}
		else if(((x1>=1 && x1<=3) && (y1==0))||(x1==2 && y1==1)){
			return true;
		}
		else if((x1==1&&y1==1)||(x1==2&&y1==2)||(x1==3&&y1==1)){
			return solve(m-1,xx,yy);
		}
		return false;
	}
}