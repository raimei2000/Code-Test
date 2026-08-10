// https://school.programmers.co.kr/learn/courses/30/lessons/1844
// 1844 게임 맵 최단거리

#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solution(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();
  queue<pair<int, int>> q;
  q.push({0, 0});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == n - 1 && y == m - 1) return maps[x][y];

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || n <= nx) continue;
      if (ny < 0 || m <= ny) continue;
      if (maps[nx][ny] == 1) {
        maps[nx][ny] += maps[x][y];
        q.push({nx, ny});
      }
    }
  }
  return -1;
}