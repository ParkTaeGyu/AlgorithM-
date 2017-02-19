#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100001][2];
int stair[100001];

int main()
{
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	memset(stair, 0, sizeof(stair));
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1][0] = 0;
	dp[1][1] = stair[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][1] = max(stair[i] + dp[i - 1][0], stair[i] + dp[i - 1][1]);
	
	}
	cout << max(dp[n][0], dp[n][1]);
	return 0;
}