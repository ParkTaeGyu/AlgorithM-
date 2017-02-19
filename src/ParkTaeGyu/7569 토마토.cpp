#include<iostream>
#include<queue>
using namespace std;
bool daychk = false;
int M, N, H, cnt = 0;
int box[101][101][101];
int dx[5] = { -1, 0, 0, 1, 0 };
int dy[5] = { 0, -1, 1, 0, 0 };
int dh[3] = { 0, -1, 1 };
queue<int> posx;
queue<int> posy;
queue<int> posk;


//H Check
int zeroCheck()
{
	for (int i = 1; i <= H; i++)
	for (int j = 1; j <= N; j++)
	for (int k = 1; k <= M; k++)
	if (box[i][j][k] == 0) return -1;
	return 0;
}
//void oneCheck()
//{
//	
//	for (int i = 1; i <= H; i++)
//		for (int j = 1; j <= N; j++)
//			for (int k = 1; k <= M; k++)
//			if (box[i][j][k] == 1 && visited[i][j][k] == 0)
//			{
//				visited[i][j][k] = 1, posx.push(k), posy.push(j), posk.push(i);
//				daychk = true;
//			}
//}
int main()
{
	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++)
	for (int j = 1; j <= N; j++)
	for (int k = 1; k <= M; k++)
	{
		cin >> box[i][j][k];
		if (box[i][j][k] == 1)
		{
			posx.push(k), posy.push(j), posk.push(i);
			daychk = true;
		}
	}
	while (!posx.empty())
	{
		cnt++;
		bool rnt = false;
		int qsize = posx.size();
		for (int i = 0; i < qsize; i++)
		{
			int x = posx.front();
			int y = posy.front();
			int k = posk.front();

			for (int j = 0; j < 5; j++)
			{
				if (x + dx[j] <= M && x + dx[j] >= 1 && y + dy[j] <= N && y + dy[j] >= 1)
				{
					if (box[k][y + dy[j]][x + dx[j]] == 0)
					{
						box[k][y + dy[j]][x + dx[j]] = 1, rnt = true;
						posk.push(k);
						posy.push(y + dy[j]);
						posx.push(x + dx[j]);
					}

				}

			}

			for (int j = 0; j < 3; j++)
			{
				if (k + dh[j] >= 1 && k + dh[j] <= H)
				{
					if (box[k + dh[j]][y][x] == 0) { box[k + dh[j]][y][x] = 1; posk.push(k + dh[j]), posx.push(x), posy.push(y); rnt = true; }
				}

			}

			posx.pop();
			posy.pop();
			posk.pop();
		}
		
		//cout << "[Day1]" << endl;
		//printBox();
		//cout << endl;
	}
	if (zeroCheck() == -1) cout << "-1" << endl;
	else cout << --cnt << endl;
	return 0;
}