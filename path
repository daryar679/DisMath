#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ifstream data("C:\\Users\\hp\\Desktop\\УЧЕБА\\input.txt");
	if (!data.is_open())
	{
		return 0;
	}
	ofstream result("C:\\Users\\hp\\Desktop\\УЧЕБА\\result.txt");

	int n = 0;
	data >> n;
	
	vector<vector<int>> matrix(n, vector <int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data >> matrix[i][j];
		}
	}

	int begin = 0;
	int end = 0;
	data >> begin >> end;
	begin--;
	end--;

	int length = -1;
	vector<int> path(n, length);

	queue<int> q;
	q.push(begin);
	path[begin] = 0;
	while (true)
	{
		if (q.empty())
		{
			result << -1;
			return 0;
		}

		int num = q.front();
		q.pop();
		
		if (num == end)
		{
			result << path[num];
			return 0;
		}

		for (int next = 0; next < n; ++next)
		{
			if (path[next] == -1 && matrix[num][next] == 1)
			{
				q.push(next);
				path[next] = path[num] + 1;
			}
		}
	}
}

