#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;
int N, K, M;
int hypertube[1001][1001];
int result[1001];
int visitedtube[1001];
int visitedstation[100001];
vector<int> link[100001];
int linksize[100001];

int main()
{
	memset(result, -1, sizeof(result));
	memset(visitedtube, -1, sizeof(visitedtube));
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
		{
			cin >> hypertube[i][j];
			link[hypertube[i][j]].push_back(i);   ///////////////wow..
		}
	
		queue<int> que;
		que.push(1);
		result[1] = 1;
		for (int i = 1; i <= N; i++)
			linksize[i] = link[i].size();

	while (!que.empty())
	{
		int posnow = que.front();
		que.pop();
		if (posnow == N)
		{
			cout << result[N] << endl;
			return 0;
		}
		for (int i = 0; i < linksize[posnow]; i++)
		{
			if (visitedtube[link[posnow][i]] != -1) continue;
			visitedtube[link[posnow][i]] = 1;

			for (int j = 0; j<K; j++) 
			{
				int next = hypertube[link[posnow][i]][j];
				if (result[next] != -1)        continue;
				result[next] = result[posnow] + 1;
				que.push(next);
			}

		}
			
	}
	
		
	cout << "-1" << endl;
}