#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>

using namespace std;

char map[13][7];
bool isVisited[13][7];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

queue<pair<int ,int>> q;
pair<int, int> p;

int ncount = 0;
int isPossible = 0;

void bfs(int y, int x, char c) {
	vector<pair<int, int>> v;
	v.push_back(make_pair(y, x));
	
	isVisited[y][x] = true;
	p.first = y;
	p.second = x;
	q.push(p);

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (!isVisited[ny][nx] && map[ny][nx] == c) {
				isVisited[ny][nx] = true;
				v.push_back(make_pair(ny, nx));
				q.push(make_pair(ny, nx));
			}
		}
	}
	
	if (v.size() >= 4) {
		isPossible++;
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = '.';
		}
	}
}
int main() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> map[i][j];
		}
	}

	int remain;
	int check = 0;
	while (true) {
		remain = 0;
		isPossible = 0;

		memset(isVisited, false, sizeof(isVisited));

		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				if (map[i][j] != '.') {
					remain++;
				}
			}
		}

		if (remain == 0) break;
		else {
			for (int i = 1; i <= 12; i++) {
				for (int j = 1; j <= 6; j++) {
					if (map[i][j] == 'R' && !isVisited[i][j]) bfs(i, j, 'R');
					if (map[i][j] == 'G' && !isVisited[i][j]) bfs(i, j, 'G');
					if (map[i][j] == 'Y' && !isVisited[i][j]) bfs(i, j, 'Y');
					if (map[i][j] == 'P' && !isVisited[i][j]) bfs(i, j, 'P');
					if (map[i][j] == 'B' && !isVisited[i][j]) bfs(i, j, 'B');
				}
			}

			if (isPossible == 0) break;
			else {
				for (int i = 1; i <= 6; i++) {
					for (int j = 12; j >= 1; j--) {
						if (map[j][i] != '.') {
							vector<char> tmp;
							for (int n = j; n >= 1; n--) {
								if (map[n][i] != '.') {
									tmp.push_back(map[n][i]);
								}
							}
								
							for (int m = 0; m < tmp.size(); m++) {
								map[12 - m][i] = tmp[m];
							}

							for (int m = 0; m < 12 - tmp.size(); m++) {
								map[m + 1][i] = '.';
							}
								
							
							break;
						}
					}
				}
				
			}
		}

		check++;
	}

	printf("%d\n", check);
	return 0;
}