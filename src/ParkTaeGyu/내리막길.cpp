#include<iostream>
#include<cstring>
using namespace std;
int map[501][501];
int dp[501][501];
int M, N;
void printdp();

/*
[입력]
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

[DP]
11111
10021
10020
11133

출력:3
*/
void DpCheck(int y,int x)
{
	if (x + 1 <= N && map[y][x+1]<map[y][x] )
	{	
			dp[y][x + 1]++;
			DpCheck(y, x + 1);
	}

	if (y + 1 <= M && map[y+1][x] <map[y][x])
	{
			dp[y + 1][x]++;
			DpCheck(y+1, x);
	}

	if (x - 1 >= 1 && map[y][x-1]<map[y][x])
	{
			dp[y][x - 1]++;
			DpCheck(y, x-1);
	}

	if (y - 1 >= 1 && map[y-1][x] <map[y][x])
	{
			dp[y - 1][x]++;
			DpCheck(y-1,x);
	}
}
void printdp()
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout<< dp[i][j];
		}
		cout << endl;
	}
}
int main()
{

	memset(map, 0, sizeof(map));
	memset(dp, 0, sizeof(dp));
	
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	dp[1][1] = 1;
	DpCheck(1, 1);
	printdp();
	cout << dp[M][N];


	return 0;
}