#include<cstdio>
#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

int map[10][10];
bool isVisited[10][10];
vector<pair<int, int>> mv;

bool line_isPossibleNum(int y, int x, int num) {
	for (int i = 1; i <= 9; i++) {
		if (map[y][i] == num || map[i][x] == num) return false;
	}
	return true;
}
bool box_isPossibleNum(int y, int x, int num) {
	int nx = (x - 1) / 3 * 3;
	int ny = (y - 1) / 3 * 3;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (map[ny + i][nx + j] == num) return false;
		}
	}
	
	return true;
}
void solve(int index) {
	
	if (index == mv.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		return;
	} else {
		int y = mv[index].first;
		int x = mv[index].second;

		for (int i = 1; i <= 9; i++) {
			if (box_isPossibleNum(y, x, i) && line_isPossibleNum(y, x, i)) {
				map[y][x] = i;
				solve(index + 1);
				map[y][x] = 0;
			}					
		}
	}
}

int main() {
	memset(isVisited, false, sizeof(isVisited));

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				mv.push_back(make_pair(i, j));
			}
		}
	}
	solve(0);
	return 0;
}