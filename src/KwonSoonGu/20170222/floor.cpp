#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int cache[100001];
int value[100001];

int solve(int index) {
	if (index == 0)
		return value[0];

	int &ret = cache[index];

	if (ret != -1) {
		return ret;
	}

	ret = max(solve(index - 1) + value[index], solve(index - 2) + value[index]);
	return ret;
}
int main() {
	int n;
	cin >> n;
	
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}

	printf("%d\n", solve(n - 1));
	return 0;
}