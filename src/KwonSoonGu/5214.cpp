#include<cstdio>
#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>
#include<string>
#define SIZE 200002

using namespace std;
vector<int> map[SIZE];
bool isVisited[SIZE];
int N, K, M;
int result = 0;

int main() {
	scanf("%d %d %d", &N, &K, &M);
	
	memset(isVisited, false, sizeof(isVisited));
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int t;
			cin >> t;
			map[i + 100001].push_back(t);
			map[t].push_back(i + 100001);
		}	
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	isVisited[1] = true;
	int last = N;
	while (!q.empty()) {
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();
		
		if (cur == last) {
			result = dis;
			break;
		}
		else {
			for (int i = 0; i < map[cur].size(); i++) {
				if (!isVisited[map[cur][i]]) {
					isVisited[map[cur][i]] = true;
					q.push(make_pair(map[cur][i], dis + 1));
				}
			}
		}
	}

	if (result == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result / 2 + 1);
	}
	return 0;
}