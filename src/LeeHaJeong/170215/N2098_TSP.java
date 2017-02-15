import java.util.Scanner;
public class N2098_TSP {
	static int N;
	static int W[][];
	static int MAX_NODE = 16;
	//중간 해를 저장할 공간, dp[from][경로(도시들의 집합)]
	static double dp[][];
	static int bitarr[];
	public static void main(String[] args){
		Scanner kbd = new Scanner(System.in);
		
		N = kbd.nextInt();
		W = new int[MAX_NODE][MAX_NODE];
		dp = new double[MAX_NODE][1<<16];
		bitarr = new int[MAX_NODE];
		
		double ans=Double.MAX_VALUE, result=0;
		
		//도시간 비용 입력
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				W[i][j] = kbd.nextInt();
				
		//bit에서의 도시 위치를 배열에 저장
		//bit[1] = 0000 0001 : 1번 도시 표시
		//bit[2] = 0000 0010 : 2번 도시 표시
		for(int i=1; i<MAX_NODE; i++)
			bitarr[i] = 1<<i;
		
		//경로 저장, path에는 모든 도시가 저장됨
		int path = 0;
		for(int i=1; i<=N; i++)
			path |= 1<<i;
		
		//출발 지점을 차례대로 바꿔서 해를 구한다.
		for(int i=1; i<=N; i++){
			int npath = (path & ~bitarr[i]);
			result = calcTSP(i, npath, N-1);
			ans = Math.min(ans, result);
			System.out.println(i+" ans : "+ans);
		}
		
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				System.out.print(dp[i][j]+" ");
			}
			System.out.println();
		}
		
		
		System.out.println(ans);
		
	}
	public static double calcTSP(int from, int path, int len){
		double res = 0;
		
		if(len == 1){
			int to = (int)Math.log(path);
			return (double)W[from][to];
		}
		
		//저장한 값을 이용
		if(dp[from][path] != 0)
			return dp[from][path];
		
		for(int i=1; i<MAX_NODE; i++){
			if((bitarr[i]&path) != 0){
				int node = bitarr[i];
				//새로운 경로는 목적지 node를 제외한 나머지 도시들
				int npath = (path&~node);
				//다음 목적지 지정, node는 2^n 값만 존재
				int to = (int)Math.log(node);
				//f(N,{N-1, N-2, ..., 1})
				//= cost[N][N-1] + f(N-1, {N-2, N-3, ... ,1})
				double fcost = calcTSP(to, npath, len-1);
				double newcost = W[from][to] + fcost;
				
				res = Math.min(res, newcost);
			}
		}
		
		//최소 비용을 저장
		dp[from][path] = res;
		
		return res;
	}
}
