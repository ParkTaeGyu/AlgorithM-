import java.util.Scanner;
public class N2098_TSP {
	static int N;
	static int W[][];
	static int MAX_NODE = 16;
	//�߰� �ظ� ������ ����, dp[from][���(���õ��� ����)]
	static double dp[][];
	static int bitarr[];
	public static void main(String[] args){
		Scanner kbd = new Scanner(System.in);
		
		N = kbd.nextInt();
		W = new int[MAX_NODE][MAX_NODE];
		dp = new double[MAX_NODE][1<<16];
		bitarr = new int[MAX_NODE];
		
		double ans=Double.MAX_VALUE, result=0;
		
		//���ð� ��� �Է�
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				W[i][j] = kbd.nextInt();
				
		//bit������ ���� ��ġ�� �迭�� ����
		//bit[1] = 0000 0001 : 1�� ���� ǥ��
		//bit[2] = 0000 0010 : 2�� ���� ǥ��
		for(int i=1; i<MAX_NODE; i++)
			bitarr[i] = 1<<i;
		
		//��� ����, path���� ��� ���ð� �����
		int path = 0;
		for(int i=1; i<=N; i++)
			path |= 1<<i;
		
		//��� ������ ���ʴ�� �ٲ㼭 �ظ� ���Ѵ�.
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
		
		//������ ���� �̿�
		if(dp[from][path] != 0)
			return dp[from][path];
		
		for(int i=1; i<MAX_NODE; i++){
			if((bitarr[i]&path) != 0){
				int node = bitarr[i];
				//���ο� ��δ� ������ node�� ������ ������ ���õ�
				int npath = (path&~node);
				//���� ������ ����, node�� 2^n ���� ����
				int to = (int)Math.log(node);
				//f(N,{N-1, N-2, ..., 1})
				//= cost[N][N-1] + f(N-1, {N-2, N-3, ... ,1})
				double fcost = calcTSP(to, npath, len-1);
				double newcost = W[from][to] + fcost;
				
				res = Math.min(res, newcost);
			}
		}
		
		//�ּ� ����� ����
		dp[from][path] = res;
		
		return res;
	}
}
