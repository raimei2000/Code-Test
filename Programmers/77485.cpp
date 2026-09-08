// https://school.programmers.co.kr/learn/courses/30/lessons/77485
// 77485 행렬 테두리 회전하기
#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int rotate(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2) {
  int min_val = 1e9;
  int prev = 0, cache = matrix[x1][y1];
  int x = x1, y = y1;
  int dir = 0;
  for (int i = 0; i < (x2 - x1 + 1) * 2 + (y2 - y1 - 1) * 2; i++) {
    if (cache < min_val) min_val = cache;
    prev = cache;
    cache = matrix[x + dx[dir]][y + dy[dir]];
    matrix[x + dx[dir]][y + dy[dir]] = prev;
    x += dx[dir];
    y += dy[dir];
    int tempx = x + dx[dir];
    int tempy = y + dy[dir];
    if (tempx < x1 || x2 < tempx || tempy < y1 || y2 < tempy) {
      dir = (dir + 1) % 4;
    }
  }
  return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<vector<int>> matrix(rows, vector<int>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = i * columns + j + 1;
    }
  }

  vector<int> answer;
  answer.reserve(queries.size());
  for (const vector<int>& q : queries) {
    answer.push_back(rotate(matrix, q[0] - 1, q[1] - 1, q[2] - 1, q[3] - 1));
  }
  return answer;
}