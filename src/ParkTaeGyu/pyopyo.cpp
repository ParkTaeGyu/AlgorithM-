#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

char map[12][6];
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 };
int visited[12][6];
int cnt = 0;                   // 같은 Color 수 카운트
int boom_cnt = 0;              // 폭발 횟수 체크
vector<int> posx;
vector<int> posy;
vector<int> v_int;
//R (빨), G(녹), B(파), P(보) , Y(노)

void IsBoomb(int y,int x,char ch) //같은 Color 수가 4개 이상인 곳을 모두 Z로 바꿈
{
	map[y][x] = 'Z';
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{

		if (x + dx[i] >= 0 && x + dx[i] <= 5 && y + dy[i] >= 0 && y + dy[i] <= 11)
		{
			if (map[y + dy[i]][x + dx[i]] == ch) IsBoomb(y + dy[i], x + dx[i],ch);
		}

	}
}
void InitData()
{
	posy.clear();
	posx.clear();
	cnt = 0;
	v_int.clear();
	memset(visited, 0, sizeof(visited));
}
void ColorCheck(int y, int x, char ch) // 같은 Color 수 카운트 하는 함수
{

	visited[y][x] = 1;
	cnt++;
	
	for (int i = 0; i < 4; i++)
	{

		if (x + dx[i] >= 0 && x + dx[i] <= 5 && y + dy[i] >= 0 && y + dy[i] <= 11)
		{
			if (map[y + dy[i]][x + dx[i]] == ch && !visited[y + dy[i]][x + dx[i]]) ColorCheck(y + dy[i], x + dx[i], ch);
		}

	}

}
void Boom() //Map 데이터중 Z가 들어가있는곳, 폭발 후 한칸씩 땡김.
{
	boom_cnt++;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == 'Z')
			{
				map[0][j] = '.';
				for (int k = i; k >= 1; k--)	
				{
					map[k][j] = map[k - 1][j];
				}
			}
		}
	}
}
void play() //게임 시작! ColorCheck함수 Call , 같은 색깔수가 4이상이면 Vector에 저장
{
	for (int i = 11; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			if (!visited[i][j] && map[i][j] != '.')
			{
				ColorCheck(i, j, map[i][j]);
				if (cnt >= 4) { v_int.push_back(cnt); posx.push_back(j); posy.push_back(i); }
				cnt = 0;
			}
		}
	}
}
void printmap()
{
	cout << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout<<map[i][j];
		}
		cout << endl;
	}
} //Map Print
bool GameEndCheck() //게임 지속할지안할지 결정..v_int라는 벡터(Colo수 체크하는 Cnt저장)이 비어있으면 같은 Color수가 4이상인 부분이 없는것이므로 게임 종료...
{
	play();
	if (v_int.empty()) return true;
	else return false;
}

/*
[입력]
......
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.

[Map 변화]
......
......
......
......
......
......
......
......
.Y....
.YG...
ZZYG..
ZZYGG.

......
......
......
......
......
......
......
......
......
..G...
.ZZG..
.ZZGG.

......
......
......
......
......
......
......
......
......
......
...Z..
..ZZZ.
3 (boom_cnt)

[입력2]
......
......
......
B.....
B.....
B.....
BRR...
BYR...
BYR...
BYR...
RRRGG.
RYRGG.

......
......
......
Z.....
Z.....
Z.....
ZZZ...
ZYZ...
ZYZ...
ZYZ...
ZZZZZ.
ZYZZZ.

......
......
......
......
......
......
......
......
.Z....
.Z....
.Z....
.Z....
2(boom_cnt)
*/


int main()
{
	
	memset(visited, 0, sizeof(visited)); // #include <cstring>
	
	//데이터 입력(map)
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> map[i][j];
		}
	}
	
	while (!GameEndCheck())         // 게임 종료 까지 반복!! 
	{
		for (int i = 0; i<posx.size();i++) 
				IsBoomb(posy[i], posx[i], map[posy[i]][posx[i]]); 

		printmap(); //맵 프린트
		Boom();   // Z인부분 폭발. boom_cnt 증가.
		InitData(); //초기화
	}

	cout << boom_cnt << endl;

	return 0;
}


