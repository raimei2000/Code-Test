// https://school.programmers.co.kr/learn/courses/30/lessons/154540
// 154540 무인도 여행

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n = 0, m = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(const vector<string>& maps, int x, int y, vector<vector<bool>>& visited) {
  if (x < 0 || n <= x || y < 0 || m <= y || maps[x][y] == 'X' || visited[x][y]) return 0;
  visited[x][y] = true;
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    sum += dfs(maps, x + dx[i], y + dy[i], visited);
  }
  return sum + (maps[x][y] - '0');
}

vector<int> solution(vector<string> maps) {
  n = maps.size();
  m = maps[0].length();
  vector<int> answer;
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = dfs(maps, i, j, visited);
      if (sum != 0) answer.push_back(sum);
    }
  }

  if (answer.empty()) return {-1};
  else {
    sort(answer.begin(), answer.end());
    return answer;
  }
}