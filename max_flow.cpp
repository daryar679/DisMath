#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int min(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int findMinCapacityOfPath(vector<int>& path,int n, vector<vector<int>> m)
{
	path.clear();
	queue<int> q;
	vector<int> visited(n, -1);
	
	visited[0] = 0;
	q.push(0);

	while (!q.empty())
	{
		int currVertex = q.front();
		q.pop();
		if (currVertex == 1)
			break;

		for (int i = 0; i < n; ++i)
		{
			if ((visited[i] == -1) && (m[currVertex][i] != 0))
			{
				visited[i] = currVertex;
				q.push(i);

				if (i == 1)
					break;
			}
		}
	}

	if (visited[1] == -1)
	{
		return 0;
	}

	int currVertex = 1;
	int capacity = m[visited[1]][1];
		
	while (currVertex != 0)
	{
		capacity = min(capacity, m[visited[currVertex]][currVertex]);
		path.push_back(currVertex);
		currVertex = visited[currVertex];
	}
	path.push_back(0);

	return capacity;
}

int main()
{
	int n = 0;
	
	ifstream data("C:\\Users\\hp\\Desktop\\УЧЕБА\\test7.in");
	if (!data.is_open())
	{
		return 0;
	}
	
	ofstream result("C:\\Users\\hp\\Desktop\\УЧЕБА\\test7.out");
	data >> n;
	
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			data >> matrix[i][j];
		}
	}

	vector<int> path;
	int max_flow = 0;
	int a, b;
	int w;
	while (w = findMinCapacityOfPath(path,n, matrix))
	{
		for (int i = 0; i < path.size() - 1; ++i)
		{
			a = path[i + 1];
			b = path[i];
			matrix[a][b] -= w;
			matrix[b][a] += w;
		}
		max_flow += w;
	}

	return 0;
}
