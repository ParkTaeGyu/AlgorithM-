#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAX 987654321

using namespace std;

int map[17][17];
int cache[17][65536];
int n;

int solve(int cur, int visited) {
	if (visited == (1 << n) - 1) return map[cur][0];

	int& ret = cache[cur][visited];
	if (ret != 0) return ret;
	
	ret = MAX;
	
	for (int next = 0; next <= n; next++) {
		if (visited&(1 << next)) continue;
		if (map[cur][next] == 0) continue;
		ret = min(ret, solve(next, visited | (1 << next)) + map[cur][next]);
	}
	return ret;
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	printf("%d", solve(0, 1));
	return 0;
}