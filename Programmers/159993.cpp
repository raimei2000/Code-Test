// https://school.programmers.co.kr/learn/courses/30/lessons/159993
// 159993 미로 탈출

#include <cctype>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(vector<string> maps) {
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};

  int n = maps.size();
  int m = maps[0].size();

  int sx, sy, ex, ey, lx, ly;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maps[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (maps[i][j] == 'E') {
        ex = i;
        ey = j;
      } else if (maps[i][j] == 'L') {
        lx = i;
        ly = j;
      }
    }
  }

  vector<vector<int>> board(n, vector<int>(m, 0));

  // 레버 찾기
  queue<pair<int, int>> que;
  que.push({sx, sy});

  bool b_lever_found = false;
  while (que.size() > 0) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || n <= nx || ny < 0 || m <= ny || maps[nx][ny] == 'X') continue;

      if ((maps[nx][ny] == 'O' || maps[nx][ny] == 'E') && board[nx][ny] == 0) {  // 안 가본 곳
        board[nx][ny] = board[x][y] + 1;
        que.push({nx, ny});
      }
      if (maps[nx][ny] == 'L') {  // 레버에 도달
        board[nx][ny] = board[x][y] + 1;
        b_lever_found = true;
        break;
      }
    }

    if (b_lever_found) break;
  }
  if (!b_lever_found) return -1;  // 레버에 도달할 수 없음

  // 출구 찾기
  queue<pair<int, int>>().swap(que);  // que 초기화
  que.push({lx, ly});

  // 레버 위치 제외하고 보드 초기화
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == lx && j == ly) continue;
      board[i][j] = 0;
    }
  }

  bool b_exit_found = false;
  while (que.size() > 0) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || n <= nx || ny < 0 || m <= ny || maps[nx][ny] == 'X') continue;

      if ((maps[nx][ny] == 'O' || maps[nx][ny] == 'S') && board[nx][ny] == 0) {
        board[nx][ny] = board[x][y] + 1;
        que.push({nx, ny});
      }
      if (maps[nx][ny] == 'E') {  // 출구에 도달
        board[nx][ny] = board[x][y] + 1;
        b_exit_found = true;
        break;
      }
    }

    if (b_exit_found) break;
  }
  if (!b_exit_found) return -1;  // 출구에 도달할 수 없음

  return board[ex][ey];
}